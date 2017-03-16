import sys

infile = open('A-small-attempt0.in')
outfile = open('out.txt', 'wb')

cases = int(infile.readline())

for case in range(0, cases):
    listt = infile.readline().split(' ')
    A = int(listt[0])
    B = int(listt[1])
    #print A, B
    P = [0]*A
    listt = infile.readline().split(' ')
    for i in range(0, A):
        P[i] = float(listt[i])
    #print P
    Pall = 1.0
    Pfirst = [0]*A
    for i in range(0, A):
        Pfirst[i] = (1-P[i])*Pall
        Pall = Pall - Pfirst[i]
    #print Pfirst, Pall
    
    K = [0]*(A+2)
    wrong = B+1
    for b in range(0, A+2):
        expect = 0
        if(b == A+1):
            stroke = B+2
            expect += stroke
        else:
            stroke = B-A+b*2+1
            expect += stroke*(sum(Pfirst[A-b:])+Pall)+(stroke+wrong)*sum(Pfirst[:A-b])
        K[b] = expect
    result = str(round(min(K),6))
    case += 1
    outfile.write('Case #'+str(case)+': '+result+'\n')

infile.close()
outfile.close()
