
def permutar(number):
    x=[]
    for i in range(1, len(number)) :
        temp = "%s%s" % (number[i:], number[0:i])
        if number < temp:
            x.append(temp)
    return set(x)


f = open('C-small-attempt0.in', 'r').read().splitlines()
n = int(f[0])
case =0
for i in range(1, n+1):
    data = f[i].split()
    A = int(data[0])
    B = int(data[1])

    count =0
    for j in range(A, B):
        
        variaciones =permutar(str(j))
        for var in variaciones:
            varI = int(var)
            if A<=varI<=B :
                count+=1
                
    print "Case #%d: %d" % (i, count)
                
        
