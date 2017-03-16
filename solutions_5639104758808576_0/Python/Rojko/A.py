T = int(input())
for t in range(1,T+1):
    m,a = input().split()
    m = int(m)
    s,v = 0,0
    for i in range(len(a)):
        x = int(a[i])
        y = max(0,i-s)
        s += x
        v += y
        s += y
        #print(i,x,s,v)
    print("Case #%d: %d" % (t,v))
