from fractions import Fraction
output = open('out.txt', 'w')
I = [line.strip().split('/') for line in open('A-large.txt')]
ma=10**12
k=0
twos=[]
while 2**k<=ma:
    twos.append(2**k)
    k+=1
for i in range(1,int(I[0][0])+1):
    ans=0;
    a=Fraction(int(I[i][0]),int(I[i][1])).numerator
    b=Fraction(int(I[i][0]),int(I[i][1])).denominator
    if b not in twos: ans='impossible'
    elif a==1: ans = twos.index(b)
    else:
        while a<b:
            a*=2
            ans+=1
    output.write("Case #"+str(i)+": "+str(ans)+"\n")
output.close()
