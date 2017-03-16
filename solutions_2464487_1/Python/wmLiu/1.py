import math

fin = open('A-large.in', 'r') 
T = int(fin.readline().rstrip())
caseNo = 0
fout = open('A-large.out', 'w')
for i in range(T):
    x = fin.readline().rstrip().split()
    r, p = int(x[0]), int(x[1])
    k = int((math.sqrt((2*r-1)*(2*r-1)+8*p)-(2*r-1))/4) + 1
    while 2*k*k+(2*r-1)*k>p:
        k -= 1
    
    #print(r, p, k)
    caseNo += 1
    fout.write('Case #' + str(caseNo) + ': ' + str(k) + '\n')

fin.close()
fout.close()

