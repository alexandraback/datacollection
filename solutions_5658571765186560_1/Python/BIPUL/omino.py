DATA = [None,1,1,2,3,3,4]
for t in range(int(input())):
    (X,R,C) = [int(s) for s in input().strip().split(" ")]
    if R>C:
        temp = R
        R = C
        C = temp
    if X<7 and (R*C)%X==0 and R>=DATA[X] and C>=X:
        print("Case #"+str(t+1)+": GABRIEL")
    else:
        print("Case #"+str(t+1)+": RICHARD")
