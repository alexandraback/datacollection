def Solve(N , s) :
    cnt = int(s[0])
    ret = 0
    for i in range(1,N+1) :
        if cnt < i :
            ret += i - cnt
            cnt += i - cnt
        cnt += int(s[i])
    return ret




fileIn = open('A-small-attempt0.in' , 'r')
fileOut = open('A-small-attempt0.out' , 'w')

Test = int(fileIn.readline())
for i in range(1,Test+1) :
    _N, s = fileIn.readline().split()
    N = int(_N)
    print >> fileOut, 'Case #'+str(i)+': '+str(Solve(N,s))

fileOut.close()
