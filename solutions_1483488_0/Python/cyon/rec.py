import sys

po=[1,10,100,1000,10000,100000,1000000,10000000,100000000]

def cycle(i):
    N = len(str(i))
    for n in xrange(1,N):
        m = i%po[n]
        p = i//po[n]
        yield m*po[N-n]+p

def solve():
    rec=set()
    A,B=map(int,raw_input().split())
    for i in xrange(A,B+1):
        for k in cycle(i):
            if i < k and k <= B and not (i,k) in rec:
                rec.add((i,k))
    return len(rec)

if __name__ == "__main__":
  t=input()
  for c in xrange(0,t):
        print "Case #{0}: {1}".format(c+1, solve())
