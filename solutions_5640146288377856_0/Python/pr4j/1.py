inp = open('A-small-attempt5.in', 'r')
otp = open('out.txt', 'w')

T = int(inp.readline())
for _ in range(T):
    R, C, W = map(int, inp.readline().split())
    if C%W==0 and C!=W and W!=1:
        ans = C//W + W - 1
    elif C!=W and W!=1:
        ans = C//W + W
    else:
        ans = C
    s = 'Case #%d: %d\n' % (_+1, ans)
    otp.write(s)

inp.close()
otp.close()
