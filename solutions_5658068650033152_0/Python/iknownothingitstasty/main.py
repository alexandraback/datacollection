repeat = int(input())
for i in range(repeat):
    n,m,k=(int(a) for a in input().split(" "))
    result = 0
    if n < 3 or m < 3:
        result = k
    elif (n,m) == (3,3):
        if k < 5:
            result = k
        else:
            result = k-1
    elif (n,m) == (3,4)or (n,m) == (4,3):
        if k < 5:
            result = k
        elif k >= 5 and k < 8:
            result = k-1
        else:
            result = k-2
    elif (n,m) == (3,5)or (n,m) == (5,3):
        if k < 5 :
            result = k
        elif k >= 5 and k <8:
            result = k-1
        elif k >=8 and k < 11:
            result = k-2
        else:
            result = k-3
    elif (n,m) == (3,6)or (n,m) == (6,3):
        if k < 5 :
            result = k
        elif k >= 5 and k <8:
            result = k-1
        elif k >=8 and k < 11:
            result = k-2
        elif k >=11 and k <14:
            result = k-3
        else:
            result = k-4
    elif (n,m) == (4,4):
        if k < 5 :
            result = k
        elif k >= 5 and k <8:
            result = k-1
        elif k >= 8 and k < 10:
            result = k-2
        elif k >=10 and k <12:
            result = k-3
        else:
            result = k-4
    elif (n,m) == (4,5)or (n,m) == (5,4):
        if k < 5 :
            result = k
        elif k >= 5 and k <8:
            result = k-1
        elif k >= 8 and k < 10:
            result = k-2
        elif k >=10 and k <12:
            result = k-3
        elif k >= 12 and k<14:
            result = k-4
        elif k >= 14 and k<16:
            result = k-5
        else:
            result = k-6
    print("Case #"+str(i+1)+": "+str(result))
    