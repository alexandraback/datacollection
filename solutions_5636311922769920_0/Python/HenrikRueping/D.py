def tobase(x,base):
    #print("xbase"+str(x)+ " "+str(base))
    b=x
    ret=[]
    while b>0:
        #print(b)
        [b,ret] = [b//len(base) if len(base)>1 else b-1,[base[b%len(base)]]+ret]
    return "b"+"".join(ret)


filename  = "D-small-attempt3.in"#"B-large.in
base = "0123456789abcdefghijklmnopqrstuvwxyz"
f = open(filename,'r')
out = open("output.out",'w')
N =int(f.readline())
print(tobase(18,"012"))
for i in range(N):
    [K,C,S]=[int(a)  for a in f.readline().split()]
    print("KCS " +str([K,C,S])+"N"+str(i))
    if S*C<K:
        out.write("Case #"+str(i+1)+": IMPOSSIBLE\n")
    else:
        buf = 1
        ret =[]
        for j in range(K):
            buf=buf+j*K**(j%C)
            if (j+1)%C ==0:
                ret.append(buf)
                buf =1
        if (buf >1)or (K==1) and (C>1):
            ret.append(buf)
        print(ret)
        print("Case #"+str(i+1)+": "+" ".join([tobase(x-1,[":"+str(k) for k in range(K)]) for x in ret]))
        print("Case #"+str(i+1)+": "+" ".join([str(x) for x in ret])+"\n")
        out.write("Case #"+str(i+1)+": "+" ".join([str(x) for x in ret])+"\n")
f.close()
out.close()
