import math

T = int(raw_input())

for i in range(0,T):
    s = raw_input()
    numbers = map(int, s.split())
    r = numbers[0]
    t = numbers[1]
    #print(r)
    #print(t)
    k = (int(math.floor((math.sqrt((2*r-1)**2+(8*t))-(2*r-1))/4)))
    tt = k*(2*r+2*k-1)
    if tt > t:
        k = k-1
    p = k+1
    ttt = p*(2*r+2*p-1)
    if ttt<=t:
        k = k+1
    print("Case #"+str(i+1)+": "+str(k))

