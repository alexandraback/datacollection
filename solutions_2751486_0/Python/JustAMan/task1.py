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
def isNvalue(s, n):
    c = 0
    for ch in s:
        if ch not in TestCase.VOWELS:
            c += 1
            if c >= n:
                return True
        else:
            c = 0
    return False

class TestCase(object):
    # define class-level constants here
    VOWELS = set('aeiou')

    def __init__(self, inp):
        # implement the reading of data here
        self.str, self.n = inp.readline().strip().split()
        self.n = int(self.n)

    def solve(self):
        if DEBUG_BREAK:
            pdb.set_trace()
        # implement solving here, store the answer as string in self.outcome
        result = 0
        for start in xrange(len(self.str)):
            for stop in xrange(start, len(self.str)):
                if (stop-start>=self.n-1) and isNvalue(self.str[start:stop+1], self.n):
                    result += 1
        self.outcome = str(result)

    def __str__(self):
        if not hasattr(self, 'outcome'):
            self.solve()
        return self.outcome
#==========================================================================

if __name__ == '__main__':
    sys.exit(main())