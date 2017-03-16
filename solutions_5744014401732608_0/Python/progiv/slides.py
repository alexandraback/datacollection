import math
import sys
sys.setrecursionlimit(1000000)
inf = open("in.in", "r")
ouf = open('out.out','w')

def close_files():
        inf.close()
        ouf.close()

printcounter = 0
def printstr(a):
        global printcounter
        printcounter +=1
        print ('Case #%d: %s' % (printcounter,a), file=ouf)

def solvetest():
        b,m = map(int, inf.readline().split())
        cnt = 2**(b-2)
        if m > cnt:
            printstr('IMPOSSIBLE')
            return
        a = [[0 for j in range(b)]for i in range(b)]
        for i in range(b):
            for j in range(i+1,b):
                a[i][j] = 1
        df = cnt//2
        cur = b-2
        #~ print(df)
        while cnt>m:
            if cnt-df>=m:
                a[cur][b-1] = 0
                #~ print(cur, b)
                #~ for i in range(b):
                    #~ a[i][cur] = 0
                cnt -= df
            df //= 2
            cur -= 1
        ans = ['POSSIBLE']
        for st in a:
            ans.append(''.join(map(str,st)))
            
        printstr('\n'.join(ans))

testnum = int(inf.readline())
for test in range(testnum):
        solvetest()
close_files()

