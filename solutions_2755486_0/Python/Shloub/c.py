for i in range(int(raw_input())):
    N=int(raw_input())
    A=[]
    for k in range(N):
        di, ni, wi, ei, si, delta_di, delta_pi, delta_si=map(int,raw_input().split())
        a=[]
        d=di
        w,e=wi,ei
        f=si
        j=0
        while j<ni:
            a.append((d,f,w,e))
            f+=delta_si
            w+=delta_pi
            e+=delta_pi
            d+=delta_di
            j+=1
        A+=a
    r=0
    A=sorted(A)
    t=[0]*1000
    af=[0]*1000
    B=[[A[0]]]
    j=1
    for d,f,w,e in A[1:]:
        if d==A[j-1][0]:
            B[-1].append((d,f,w,e))
        else:
            B.append([(d,f,w,e)])
        j+=1
    for A in B:
        for a in A:
            if any(j<a[1] for j in t[a[2]+500:a[3]+501]+af[a[2]+500:a[3]+500]):
                r+=1
               #  print "s"
            # else:
            #     print "f"
        for a in A:
            for j in range(a[2]+500,a[3]+500):
                t[j]=max(t[j],a[1])
                af[j]=max(af[j],a[1])
            j=a[3]+500
            t[j]=max(t[j],a[1])
    # print B
    print"Case #"+str(i+1)+":",r
