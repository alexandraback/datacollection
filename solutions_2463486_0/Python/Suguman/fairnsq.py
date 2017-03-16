def evaluate(a,b):
    if a<=1:
        first = 0
    elif a<=4:
        first = 1
    elif a<=9:
        first = 2
    elif a <= 121:
        first = 3
    elif a <= 484:
        first = 4
    else:
        first = 5
        
    if b>= 484:
        sec = 5
    elif b>= 121:
        sec = 4
    elif b>= 9:
        sec = 3
    elif b>= 4:
        sec = 2
    elif b>= 1:
        sec = 1
    else:
        sec = 0
            
    return(sec-first)

infile = open('/home/suguman/Desktop/C-small-attempt0.in','r')
outfile = open('/home/suguman/Desktop/output3.txt','w')

x = int(infile.readline())
i=0
while i<x:
    l1 = (infile.readline()).split()
    a = int(l1[0])
    b = int(l1[1])
    outfile.write('Case #'+str(i+1)+': ' + str(evaluate(a,b))+'\n')
    i+=1


outfile.close()
infile.close() 
