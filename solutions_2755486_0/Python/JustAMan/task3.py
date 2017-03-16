import multiprocessing
import sys
import pdb
import time

RUN_PARALLEL = False
DEBUG_BREAK = None

def main():
    global RUN_PARALLEL, DEBUG_BREAK
    start = time.time()
    if len(sys.argv[1:]) < 1:
        print >>sys.stderr, 'Usage: %s input-file-name [-d|-dbg] [-p|-parallel]' % sys.argv[0]
        return 1

    if len(sys.argv[1:]) > 1:
        for param in sys.argv[2:]:
            param = param.lower()
            if param in ('-p', '-parallel'):
                RUN_PARALLEL = True
            elif param in ('-d', '-dbg'):
                DEBUG_BREAK = True
            else:
                print >>sys.stderr, 'Unknown parameter %s' % param
                return 2
        DEBUG_BREAK = DEBUG_BREAK and (not RUN_PARALLEL)
    tests = []
    with open(sys.argv[1], 'r') as inp:
        T = int(inp.readline().strip())
        for t in xrange(T):
            # read data
            tests.append(TestCase(inp))
    
    if RUN_PARALLEL:
        pool = multiprocessing.Pool()
        mapper = pool.map
        closer = lambda: [pool.close(), pool.join()] and None
    else:
        mapper = map
        closer = lambda: None
    # now do the job! :)
    results = mapper(str, tests)
    closer()

    # now output the counted data
    for t, test in enumerate(results):
        print 'Case #%d: %s' % (t + 1, test)
    print >>sys.stderr, 'took %s to run' % (time.time() - start)

    return 0

#==========================================================================
import collections, copy
Tribe = collections.namedtuple('Tribe', 'day0 attacks west east strength deltaD deltaP deltaS')
Brick = collections.namedtuple('Brick', 'west east height')

def getMinWall(wall, west, east):
    if not wall:
        return 0
    if west < wall[0].west:
        return 0
    if east > wall[-1].east:
        return 0
    minimum = None
    for brick in wall:
        if (brick.west <= west < brick.east) or \
           (brick.west < east <= brick.east) or \
           (brick.west >= west and brick.east <= east):
                if minimum is None or brick.height < minimum:
                    minimum = brick.height
    return minimum

def findPoint(wall, p):
    for idx, brick in enumerate(wall):
        if (brick.west <= p <= brick.east):
            return idx
    return None

def buildWall(wall, tribe):
    if not wall:
        wall = [Brick(tribe.west, tribe.east, tribe.strength)]
    elif tribe.east < wall[0].west:
        wall = [Brick(tribe.west, tribe.east, tribe.strength),
                Brick(tribe.east, wall[0].west, 0)] + wall
    elif tribe.west > wall[-1].east:
        wall.extend([Brick(wall[-1].east, tribe.west, 0),
                     Brick(tribe.west, tribe.east, tribe.strength)])
    else:
        #if tribe.day0 == 2:
        #    pdb.set_trace()
        if tribe.west < wall[0].west:
            wall, tribe = [Brick(tribe.west, wall[0].west, tribe.strength)] + wall,\
                    Tribe(day0=tribe.day0, attacks=tribe.attacks,
                          west=wall[0].west, east=tribe.east,
                          strength=tribe.strength, 
                          deltaD=tribe.deltaD, deltaP=tribe.deltaP, deltaS=tribe.deltaS)
        if tribe.east > wall[-1].east:
            wall, tribe = wall + [Brick(wall[-1].east, tribe.east, tribe.strength)],\
                    Tribe(day0=tribe.day0, attacks=tribe.attacks,
                          west=tribe.west, east=wall[-1].east,
                          strength=tribe.strength, 
                          deltaD=tribe.deltaD, deltaP=tribe.deltaP, deltaS=tribe.deltaS)

        start, stop = findPoint(wall, tribe.west), findPoint(wall, tribe.east)
        #if stop == start and tribe.strength > wall[start].height:
        #    wall[start:stop+1] = [Brick(wall[start].west, tribe.west, wall[start].height),
        #                          Brick(tribe.west, tribe.east, tribe.strength),
        #                          Brick(tribe.east, wall[stop].east, wall[stop].height)]
        #else:
        for idx in xrange(stop, start - 1, -1):
            blocks, brickStart, brickStop = [None], tribe.west, tribe.east
            if wall[idx].west < tribe.west:
                blocks = [Brick(wall[idx].west, tribe.west, wall[idx].height)] + blocks
            else:
                brickStart = wall[idx].west
            if wall[idx].east > tribe.east:
                blocks = blocks + [Brick(tribe.east, wall[idx].east, wall[idx].height)]
            else:
                brickStop = wall[idx].east
            blocks[blocks.index(None)] = Brick(brickStart, brickStop, max(wall[idx].height, tribe.strength))
            wall[idx:idx+1] = blocks
    return wall


def attackTheWall(wall, tribes):
    breaches = []
    for tribe in tribes:
        if getMinWall(wall, tribe.west, tribe.east) < tribe.strength:
            breaches.append(tribe)
    for tribe in breaches:
        wall = buildWall(wall, tribe)
    return wall, len(breaches)

class TestCase(object):
    # define class-level constants here

    def __init__(self, inp):
        # implement the reading of data here
        #self.str, self.n = inp.readline().strip().split()
        #self.n = int(self.n)
        nTribes = int(inp.readline().strip())
        tribes = []
        for n in xrange(nTribes):
            tribes.append(Tribe(*[int(x) for x in inp.readline().strip().split()]))
            #day0 attacks west0 east0 str0 deltaD deltaP deltaS
        self.tribes = tribes

    def solve(self):
        if DEBUG_BREAK:
            pdb.set_trace()
        # implement solving here, store the answer as string in self.outcome
        wall = []
        attacks = collections.defaultdict(list)
        for tribe in self.tribes:
            for n in xrange(tribe.attacks):
                attacks[tribe.day0 + n * tribe.deltaD].append(
                    Tribe(day0=tribe.day0 + n * tribe.deltaD, attacks=tribe.attacks,
                          west=tribe.west + n * tribe.deltaP, east=tribe.east + n * tribe.deltaP,
                          strength=tribe.strength + n * tribe.deltaS, 
                          deltaD=tribe.deltaD, deltaP=tribe.deltaP, deltaS=tribe.deltaS))
        result = 0
        for day in sorted(attacks.keys()):
            wall, breaches = attackTheWall(wall, attacks[day])
            result += breaches
        self.outcome = str(result)

    def __str__(self):
        if not hasattr(self, 'outcome'):
            self.solve()
        return self.outcome
#==========================================================================

if __name__ == '__main__':
    sys.exit(main())