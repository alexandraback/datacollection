#!/usr/bin/env python


def sums(N, S):
    cur = set()
    for i in xrange(N):
        prev = list(cur)
        if S[i] in cur:
            return S[i], i
        cur.add(S[i])
        for p in prev:
            n = S[i] + p
            if n in cur:
                # we found that sum -> N has never appeared so far.
                return n, i
            cur.add(n)
    return False, False, cur

SUBSETS = lambda l: reduce(lambda z, x: z + [y + [x] for y in z], l, [[]])
def findset(N, S, n):
    #print 'findset', N, n
    for _set in SUBSETS(range(N)):
        if n == sum( S[i] for i in _set ):
            return set(_set)
    return None

def find(S, n, i):
    #print 'find', n, i
    a = findset(i, S, n)
    b = findset(i, S, n - S[i])
    b.add( i )
    a1 = a.difference(b)
    b1 = b.difference(a)
    assert i in b1 and a1

    return [S[i] for i in b1], [S[i] for i in a1]

def case(N, S):
    S.sort()
    res = sums(N, S)
    if res[0] is False:
        return "Impossible" 
    print "got ", res, ' of' , S
    res1, res2 = find(S, res[0],res[1])
    return "\n%s\n%s" % (' '.join(map(str,res1)), ' '.join(map(str,res2)))

def solve(fin, fout):
    T = int(fin.readline())
    for t in xrange(T):
        R = map(int, fin.readline().strip().split(' '))
        N = R[0]
        S = R[1:]
        fout.write("Case #%i: %s\n" % (t+1, case(N,S)) )
    return True

if __name__ == "__main__":
    import sys
    with open(sys.argv[1],'r') as fin:
        with open(sys.argv[2], 'w') as fout:
            solve(fin, fout)
