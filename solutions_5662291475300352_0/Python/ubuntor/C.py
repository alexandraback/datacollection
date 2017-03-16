s = open("in")
n2 = int(s.readline().strip())

o = open("out","w")

for i in range(1,n2+1):
    n = int(s.readline().strip())
    hi = []
    th = 0
    ans = 0
    for j in range(n):
        d,h,m = [int(j) for j in s.readline().strip().split()]
        hi.append((d,h,m))
        th += h
    if th > 1:
        first = last = None
        if n == 1:
            first = (hi[0][0],hi[0][2]+1)
            last = (hi[0][0],hi[0][2])
        else:
            first = (hi[0][0],hi[0][2])
            last = (hi[1][0],hi[1][2])
            if first[0] > last[0]:
                first, last = last, first
        print(first,last)
        time = first[1] * (360-first[0]) / 360
        distance = (first[0] - last[0]) % 360
        if distance == 0:
            distance = 360
        if last[1] != first[1]:
            relspeed = 360/last[1] - 360/first[1]
            t2 = distance/relspeed
            print(time,distance,relspeed,t2)
            if relspeed > 0 and distance < time * relspeed:
                ans = 1
    o.write("Case #"+str(i)+": "+str(ans)+"\n")
