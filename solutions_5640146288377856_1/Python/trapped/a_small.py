T = int(raw_input())

def solve(r, c, w):
    if w == 1: return r*c
    if w == c: return (r-1) + c
    return (r-1)*(c//w) + solve1(c,w)

def solve1(c,w):
    # following only for small case: r=1
    if w > c//2: return w+1
    if w == c//2: return w+1+(c%2)
    return 1+ solve1(c-w, w)
    

for t in range(1,T+1):
    r, c, w = map(int, raw_input().strip().split())
    print "Case #%d: %d"%(t, solve(r,c,w))
