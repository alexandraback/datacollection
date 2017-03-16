T = int(raw_input())

def solve(r, c, w):
    if w == 1: return r*c
    if w == c: return (r-1) + c
    # following only for small case: r=1
    if w > c//2: return w+1
    if w == c//2: return w+1+(c%2)
    return 1+ solve(r, c-w, w)
    
    '''if c%2 == 1:
        ans = 1 + (c//2)//w
        ans += solve(r, c//2, w)
    else:
        ans = 1 + (c//2 - 1)//w
        ans += solve(r, c//2, w)
    return ans'''
    

for t in range(1,T+1):
    r, c, w = map(int, raw_input().strip().split())
    print "Case #%d: %d"%(t, solve(r,c,w))
