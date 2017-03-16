
import sys
sys.stdin=open('C:\\Users\\zw\\Downloads\\hack\\1.in')
sys.stdout=open('C:\\Users\\zw\\Downloads\\hack\\1.out', 'w')
def solve(c, w, now):
    if c==w or w==1: return now+c
    if 2*w>c:
        overlap=2*w-c
        return solve(c-overlap, w-overlap, now+overlap)
    return max(solve(c-w,w,now+1), solve(2*w-2,w-1,now+1))
for t in range(input()):
    r,c,w=map(int,raw_input().split())
    print 'Case #%d: %d' % (t+1, solve(c,w,0)+(r-1)*(c/w))