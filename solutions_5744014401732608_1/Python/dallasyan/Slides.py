lcounter=0
with open("inp.txt") as f:
    with open("out.txt","w+") as g:
        for line in f:
            if lcounter>0:
                pathsTo=[]
                twoDMatrix=[]
                oneDMatrix=[]
                if lcounter>1:
                    g.write("\n")
                g.write("Case #"+str(lcounter)+": ")
                line=line.strip().split()
                for i in range(len(line)):
                    line[i]=int(line[i])
                for i in range(line[0]):
                    pathsTo.append(0)
                    twoDMatrix.append([])
                    for j in range(line[0]):
                        twoDMatrix[i].append(0)
                pathsTo[0]=1
                if line[1]>2**(line[0]-2):
                    g.write("IMPOSSIBLE")
                else:
                    g.write("POSSIBLE")
                    if line[1]>0:
                        for i in range(line[0]-1):
                            twoDMatrix[i][i+1]=1
                            pathsTo[i+1]+=1
                    line[1]-=1
                    k=2
                    while line[1]>0:
                        pathsTo[k]=pathsTo[k-1]
                        for i in range(k-2,-1,-1):
                            if line[1]>=pathsTo[i]:
                                twoDMatrix[i][k]=1
                                line[1]-=pathsTo[i]
                                pathsTo[k]+=pathsTo[i]
                        k+=1
                    for i in range(len(twoDMatrix)):
                        g.write("\n")
                        for k in range(len(twoDMatrix)):
                            g.write(str(twoDMatrix[i][k]))
            lcounter+=1
                        
