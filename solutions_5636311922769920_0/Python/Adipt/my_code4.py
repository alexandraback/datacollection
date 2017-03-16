t = int(raw_input().strip())
i = 0
while t>0:
    t-=1
    i+=1
    k, c, s = tuple(map(int, raw_input().strip().split()))
    """if c==1:
        if k>s:
            print "Case #%d:" %(i), "IMPOSSIBLE"
            continue
        else:
            print "Case #%d:" %(i), ' '.join(map(str, range(1, k+1)))
            continue
    elif s<(int(k/2)+(k%2)):
        print "Case #%d:" %(i), "IMPOSSIBLE"
        continue
    else:
        arr = ['2']
        while s>0:
            temp = int(arr[-1])+2+2*(k**(c-1))
            if temp<=(k**c):
                arr.append(str(temp))
                s-=1
            else:
                if temp == (k**c)+1:
                    arr.append(str(temp-1))
                break
        r = ' '.join(arr)"""
    if k>=s+c:
        print "Case #%d:" %i, "IMPOSSIBLE"
        continue
    elif k<=s:
        print "Case #%d:" %i, " ".join(map(str, range(1, k+1)))
        continue
    a = []
    b = 1
    d = 1
    f = 1
    while d<=s:
        e=c
        b = f
        while e>1:
            e-= 1
            b = (b-1)*k+b+1
            f+=1
        a.append(str(b))
        if f>=k:
            break
    a = ' '.join(a)
    print "Case #%d:" %(i), a
