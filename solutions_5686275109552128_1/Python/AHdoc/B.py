MAXP = 1000

C = [[0 for j in range(MAXP+1)] for i in range(MAXP+1)]

def DIV(x) :
    if x % 2 == 0 :
        return x / 2
    else :
        return int(x / 2) + 1

def Prepare() :
    for i in range(MAXP+1) :
        for j in range(MAXP+1) :
            if j <= i :
                C[j][i] = 0
            else :
                C[j][i] = 1 + C[j-i][i]

def Solve(N , A) :
    ret = MAXP
    for i in range(1,MAXP) :
        tmp = 0
        for j in range(N) :
            tmp += C[A[j]][i]
        if i + tmp < ret :
            ret = i + tmp
    return ret

#fileIn = open('B.in' , 'r')
#fileOut = open('B.out' , 'w')
#fileIn = open('B-small-attempt0.in' , 'r')
#fileOut = open('B-small-attempt0.out' , 'w')
#fileIn = open('B-small-attempt1.in' , 'r')
#fileOut = open('B-small-attempt1.out' , 'w')
#fileIn = open('B-small-attempt2.in' , 'r')
#fileOut = open('B-small-attempt2.out' , 'w')
#fileIn = open('B-small-attempt3.in' , 'r')
#fileOut = open('B-small-attempt3.out' , 'w')
fileIn = open('B-large.in' , 'r')
fileOut = open('B-large.out' , 'w')

Prepare()
Test = int(fileIn.readline())
for i in range(1,Test+1) :
    N = int(fileIn.readline())
    A = [int(x) for x in fileIn.readline().split()]
    print >> fileOut, 'Case #'+str(i)+': '+str(Solve(N,A))

fileIn.close()
fileOut.close()
