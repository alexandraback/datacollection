from __future__ import division


def solvecase(level, h, w, ceilings, floors):
    def neighbours(x,y):
        n=[]
        if x>0: n.append((x-1,y))
        if y>0: n.append((x,y-1))
        if x<w-1: n.append((x+1,y))
        if y<h-1: n.append((x,y+1))
        return n
    def level_at_time(t):
        return max(level - t, 0)
    def time_for_level(l):
        return level - l

    mintimes = [[None for x in xrange(w)] for y in xrange(h)]
    mintimes[0][0] = 0
    q = neighbours(0,0)

    while len(q)>0:
        x,y = q.pop()
        #print len(q)
        target_ceiling = ceilings[y][x]
        target_floor = floors[y][x]
        for x2,y2 in neighbours(x,y):
            if mintimes[y2][x2] is None:
                continue
            source_ceiling = ceilings[y2][x2]
            source_floor = floors[y2][x2]
            if source_floor + 50 > target_ceiling:
                continue
            if target_floor + 50 > target_ceiling:
                continue
            if target_floor + 50 > source_ceiling:
                continue
            current_level = level_at_time(mintimes[y2][x2])
            if current_level + 50 <= target_ceiling:
                # We can go straight away.
                time_to_move = mintimes[y2][x2]
                if time_to_move == 0:
                    if mintimes[y][x] == 0:
                        continue
                    mintimes[y][x] = 0
                    q.extend(neighbours(x,y))
                    continue
            else:
                # We have to wait until the water is low enough.
                time_to_move = time_for_level(target_ceiling - 50)
            current_level = level_at_time(time_to_move)
            if current_level - 20 >= source_floor:
                new_time = time_to_move + 10
            else:
                new_time = time_to_move + 100
            if mintimes[y][x] is not None:
                if mintimes[y][x] <= new_time:
                    continue
            #print "pip", y, x, new_time, mintimes[y][x]
            mintimes[y][x] = new_time
            q.extend(neighbours(x,y))
    return mintimes[h-1][w-1] / 10


def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        h, n, m = [int(s) for s in raw_input().split()]
        ceilings = [[int(s) for s in raw_input().split()] for j in xrange(n)]
        floors = [[int(s) for s in raw_input().split()] for j in xrange(n)]
        result = solvecase(h, n, m, ceilings, floors)
        print "Case #{0}: {1}".format(i+1, result)

if __name__ == "__main__":
    main()

