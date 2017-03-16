for t in range(int(input())):
    (X,R,C) = [int(s) for s in input().strip().split(" ")]
    if R>C:
        temp = R
        R = C
        C = temp
    if (R*C)%X==0 and R>=(X-1) and C>=X:
        print("Case #"+str(t+1)+": GABRIEL")
    else:
        print("Case #"+str(t+1)+": RICHARD")
