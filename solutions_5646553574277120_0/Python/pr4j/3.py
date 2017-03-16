inp = open('C-small-attempt0.in', 'r')
otp = open('out.txt', 'w')
        
T = int(inp.readline())
for _ in range(T):
    C, D, V = map(int, inp.readline().split())
    Dx = map(int, inp.readline().split())
    L = [1,3,6,10,15,21,28,36]
    for i in range(1,len(L)):
        if V>L[i-1] and V<=L[i]:
            ans = range(1,i+2)
            break
    for j in Dx:
        if j in ans:
            ans.remove(j)
    s = 'Case #%d: %d\n' % (_+1, len(ans))
    otp.write(s)

inp.close()
otp.close()
