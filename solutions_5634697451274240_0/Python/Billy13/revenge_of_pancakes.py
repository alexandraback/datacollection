inp = open("in1.txt", "r")
out = open("out2.txt","w")
T= int((inp.readline()).rstrip())
for i in range(T):
    line=(inp.readline()).rstrip()
    args=list(line)
    met=0
    j=len(args)-1
    while True:
        while j>=0:
            if args[j]=="-":
                break
            j-=1
        if j<0:
            break
        else:
            while True:
                temp=[]
                t=0
                while t<=j:
                    temp.append(args[t])
                    t+=1
                temp.reverse()
                t=0
                while t<=j:
                    if temp[t]=='+':
                        temp[t]='-'
                    else:
                        temp[t]='+'
                    t+=1
                if temp[j]!=args[j]:
                    met+=1
                    t=0
                    while t<=j:
                        args[t]=temp[t]
                        t+=1
                    break
                else:
                    j-=1
            j=len(args)-1
    out.write("Case #" + str(i+1) + ": " + str(met) + "\n")
