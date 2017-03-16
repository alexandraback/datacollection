t = input()
for ttt in range(t):
    r, c, w = map(int, raw_input().split())
    if c % w == 0:
        re = c / w - 1 + w
    else:
        re = c / w - 1 + w + 1
    if r != 1:
        re = c / w * (r - 1) + re
    print 'Case #%d:'%(ttt+1), re