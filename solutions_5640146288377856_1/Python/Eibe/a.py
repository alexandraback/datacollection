def solve(r,c,w):
    cnt = c/w-1
    c -= cnt * w
    cnt *= r
    cnt += r - 1
    if c == w:
        return cnt + w
    else:
        return cnt + w + 1

t = int(raw_input())
for case in range(1, t+1):
    r, c, w = map(int, raw_input().split())
    print "Case #%i: %i" %(case, solve(r,c,w))
