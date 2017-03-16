import heapq
from Queue import deque
from itertools import product, combinations

def suround(r, c, m, i, j):
    for ai,aj in product([-1,0,1], repeat=2):
        ii, jj = i+ai, j+aj
        if 0<=ii<r and 0<=jj<c and (ii or jj):
            yield (ii, jj)

def frozen(ly):
    return tuple(map(tuple, ly))

def unfrozen(fly):
    return list(map(list, fly))

def show(ly):
    return '\n'.join([''.join(l) for l in ly])

def search(r, c, m):
    ly = [['*']*c for i in xrange(r)]
    ly[0][0] = 'c'
    cm = r*c-1
    if cm == m:
        return ly

    for i, j in suround(r,c,m,0,0):
        ly[i][j] = '.'
        cm -= 1

    if c > 2 and cm - (c-2)*2 >= m+c:
        for i in [0, 1]:
            for j in xrange(2, c):
                assert ly[i][j] == '*'
                ly[i][j] = '.'
                cm -= 1
        i = 2
        while cm-c >= m+c:
            for j in xrange(c):
                assert ly[i][j] == '*'
                ly[i][j] = '.'
                cm -= 1
            i += 1

    #print 'init', cm
    #print show(ly)

    if cm < m:
        return None

    q = [(cm, frozen(ly))]
    saw = set()
    while q:
        cm, fly = heapq.heappop(q)
        #print cm, len(q)
        #print show(fly)

        if cm == m:
            #print path
            return fly
        if fly in saw:
            continue
        saw.add(fly)

        ly = unfrozen(fly)

        for i in xrange(r):
            for j in xrange(c):
                if ly[i][j] != '.':
                    continue
                changed = []
                for ii,jj in suround(r,c,m,i,j):
                    if ly[ii][jj] == '*':
                        ly[ii][jj] = '.'
                        changed.append((ii,jj))

                if changed and cm-len(changed) >= m:
                    heapq.heappush(q, (cm-len(changed), frozen(ly)))

                for ii,jj in changed:
                    ly[ii][jj] = '*'
    return None

if __name__ == '__main__':
    cases = int(raw_input())
    for cas in xrange(cases):
        print "Case #%d:" % (cas+1)
        r, c, m = map(int, raw_input().split())
        ly = search(r, c, m)
        if ly is None:
            print 'Impossible'
        else:
            print show(ly)
