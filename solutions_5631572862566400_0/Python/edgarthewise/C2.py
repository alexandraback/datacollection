import sys

def getInt(f):
    return int(f.readline().strip())

def getLine(f):
    return f.readline().strip()

def getInts(f):
    return [int(i) for i in f.readline().strip().split()]

#with open('/home/edgar/C-small-attempt0.in') as f:
with sys.stdin as f:
    T = getInt(f)
    for t in xrange(1,T+1):
        N = getInt(f)
        F = [i-1 for i in getInts(f)]
        
        cycle_len = [0]*N
        tail_len = [0]*N 
        for i in xrange(N):
            path_ix = dict()
            j = i
            for n in xrange(N+1):
                if j in path_ix:
                    break
                path_ix[j] = n
                j = F[j]
            cl = n - path_ix[j]
            if cycle_len[j]==0:
                cycle_len[j] = cl
            else:
                assert cycle_len[j]==cl
            tail_len[j] = max(tail_len[j], path_ix[j])

        best = 0
        for i in xrange(N):
            if cycle_len[i] == 2 and F[i]>i:
                best += tail_len[i] + tail_len[F[i]] + 2

        for i in xrange(N):
            if cycle_len[i] >= 3:
                best = max(best, cycle_len[i])

        print 'Case #%d: %d' % (t, best)
        sys.stdout.flush()

