#f = open("A-small-attempt2.in",'r')
f = open("A-large.in",'r')
#f = open("A-sample.in",'r')
output  = open("output.txt",'w')
cases =int(f.readline())
for case in range(1,cases+1):
    N=int(f.readline())
    #print(N)
    steps =0
    while N>11:
        #print([N,steps])
        if N%10==0:
            N-=1
            steps+=1
        else:
            if N==int(str(N)[::-1]):
                N-=1
                steps+=1
            else:  
                half = (len(str(N))+1)//2
                steps+=(N%(10**half))-1
                N-=(N%(10**half))-1
                if  N!=int(str(N)[::-1]):
                    steps+=1
                    N=int(str(N)[::-1])
    steps+=N
    output.write("Case #"+str(case)+": "+str(steps)+"\n")
    print("Case #"+str(case)+": "+str(steps)+"\n")
output.close()
f.close()
