for tt in range(int(input())):
    c, f, x = map(float, input().split())

    t = 0
    r = 2
    while True:
#          print("time:",t,"rate:",r)
        t1 = x/r
        t2 = x/(f+r) + c/r
#          print("finish no buy:",t1,"finish buy:", t2)
        if t1 < t2:
            t += t1
            break
        t += c/r
        r += f

    print ("Case #{}: {:.7f}".format(tt+1, t))
