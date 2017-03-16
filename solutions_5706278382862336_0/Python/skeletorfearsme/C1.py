output = open('out.txt', 'w') # Output File
I = [line.strip().split('/') for line in open('A-small-attempt0.txt')]
ma=1000
k=0
twos=[]
while 2**k<=ma:
    twos.append(2**k)
    k+=1
for i in range(1,int(I[0][0])+1):
    ans=0;
    if int(I[i][1]) not in twos: ans='impossible'
    elif int(I[i][0])==1: ans= twos.index(int(I[i][1]))
    else:
        a=int(I[i][0])
        b=int(I[i][1])
        while a<b:
            a*=2
            ans+=1
    output.write("Case #"+str(i)+": "+str(ans)+"\n")
output.close()
