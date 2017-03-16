import math

inp = open("in3.txt", "r")
out = open("out5.txt","w")
T= int((inp.readline()).rstrip())
for i in range(T):
    args=((inp.readline()).rstrip()).split()
    K=int(args[0])
    C=int(args[1])
    S=int(args[2])
    if K==S:
        out.write("Case #" + str(i+1) + ": ")
        for j in range(S-1):
            out.write(str(j+1)+" ")
        out.write(str(S)+"\n")
    else:
        ans=[]
        j=0
        pos=0
        while j<K:
            sum=0
            met=0
            while C-met>0:
                if met+j>=K:
                    j=K
                    break
                sum+=(j+met)*(K**(C-met-1))
                met+=1
            ans.append(sum+1)
            j+=met
            pos+=1
        if(pos<S):
            out.write("Case #" + str(i+1) + ": ")
            k=0
            while k<len(ans)-1:
                out.write(str(ans[k])+" ")
                k+=1
            out.write(str(ans[len(ans)-1])+"\n")
        else:
            out.write("Case #" + str(i+1) + ": IMPOSSIBLE\n")