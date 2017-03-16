T=int(input())
for i in range (T):
    line1=input().split()
    B=int(line1[0])
    M=int(line1[1])
    if (M>2**(B-2)):
        print ("Case #" + str(i+1) + ": IMPOSSIBLE")
    else:
        print ("Case #" + str(i+1) + ": POSSIBLE")
        myout=[]
        for j in range (B):
            thisline=[]
            for k in range (B):
                thisline.append("0")
            myout.append(thisline)
        binnum=bin(M)[2:]
        binnum=(B-1-len(binnum))*"0" + binnum

        binnum=binnum[::-1]
        
        for j in range (B-2):
            for k in range (j+1,B-1):
                myout[j][k]="1"
        if (binnum[-1]=="0"):
            for j in range (B-1):
                if binnum[j]=="1":
                    myout[j+1][B-1]="1"
        else:
            for j in range(B-1):
                myout[j][B-1]="1"
        for j in range (B):
            out=""
            for k in range (B):
                out+=myout[j][k]
            print(out)
        

