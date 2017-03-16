import sys

def solve(A, motes):
    numleft = []
    motes.sort()
    while motes:
        if A>motes[0]:
            A += motes[0]
            motes.pop(0)
        else:
#            for add in added:
#                added[0] += 1
#            added.append([1, len(motes)])
            if A == 1: return len(motes)
#            print >>sys.stderr,'adding mote of size',A-1,'at pos',len(motes),'from end'
            numleft.append(len(motes))
            A += (A-1)
    if not numleft:
        return 0
    m = len(numleft)
    for i,num in enumerate(numleft):
        if i+num < m:
            m = i+num
    return m

T = int(raw_input())
for i in xrange(T):
    A,N = map(int, raw_input().split())
    motes = map(int, raw_input().split())
    print >>sys.stderr, i
    print 'Case #%d: %d' % (i+1, solve(A,motes))
