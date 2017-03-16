A=0
B=0
def permutar(number):
    x=[]
    temp=''
    nTemp=0
    for i in range(1, len(number)) :
        temp = number[i:] + number[0:i]
        nTemp=int(temp) 
        if int(number) < nTemp and A<=nTemp<=B :
            x.append(temp)
    x = set(x)
    return len(x)


f = open('C-large.in', 'r').read().splitlines()
n = int(f[0])
case =0
for i in range(1, n+1):
    data = f[i].split()
    A = int(data[0])
    B = int(data[1])

    count =0
    for j in range(A, B):
        count += permutar(str(j))
                
    print "Case #%d: %d" % (i, count)
                
        
