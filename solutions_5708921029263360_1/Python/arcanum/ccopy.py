from math import *

def rl(l): return range(len(l))



f = open("clarge.out", mode='w')

T = int(input())

def works(l, J,P,S,K): # testing only

    seen1 = dict()
    seen2 = dict()
    seen3 = dict()
    seenall = dict()

    for a1 in range(J):
        for a2 in range(P):
            for a3 in range(len(l[0][0])):
                ## variable misnaming

                i,j,k = l[a1][a2][a3]
                if i >= J or j >= P or k >= S:
                    return False
                
                if (i,j) in seen3:
                    seen3[(i,j)] += 1
                else:
                    seen3[(i,j)] = 1
                    
                if (i,k) in seen2:
                    seen2[(i,k)] += 1
                else:
                    seen2[(i,k)] = 1

                if (j,k) in seen1:
                    seen1[(j,k)] += 1
                else:
                    seen1[(j,k)] = 1

                if (i,j,k) in seenall:
                    seenall[(i,j,k)] += 1
                else:
                    seenall[(i,j,k)] = 1

    dnum = 0
    for dn in [seen1,seen2,seen3]:
        dnum += 1
        for e in dn:
            if dn[e] > K:
                print("Error with",e,dn[e],"in",dnum,dn)
                return False
    return True
                
                

for nt in range(1, T+1):
    J, P, S, K = list(map(int, input().split()))

    # the easy part - the first two
    ans = [[[[i, j, -1] for k in range(min(S,K))] for j in range(P)] for i in range(J)] # too pythony
    #print("initial ans", ans)
    numtimes = min(S,K)*P*J
    
    if K < S: # hard case
        
        for i in range(J):
            for j in range(P):
                for k in range(len(ans[0][0])):
                    ans[i][j][k][2] = (i + j + k)%S # first attempt

    else:
        for i in range(J):
            for j in range(P):
                for k in range(S):
                    ans[i][j][k][2] = k
        
    #print(ans)
    #theans = "\n".join(" ".join(str(e) for e in (je for je in (ie for ie in ans))))

    theans = ""
    for i in range(J):
        for j in range(P):
            for k in range(min(K,S)):
                toadd=''

                for mnum in range(3):
                
                    toadd += str(ans[i][j][k][mnum]+1)+" " # 1-indexed!
                toadd = toadd[:-1]
                toadd +='\n'
                theans += toadd

    
    towrite = "Case #"+str(nt)+": "+str(numtimes)+'\n'+theans
    f.write(towrite)
    #print(towrite, end="")

    #print("Case #"+str(nt)+": "+str(numtimes))
    #print(works(ans,J,P,S,K))
    
f.close()


'''
4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1

32
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
3 3 3 2
4 4 4 3
3 4 4 2
3 4 4 3
5 7 9 4
5 7 9 5
5 7 9 6
5 7 9 7
5 7 9 8
5 7 9 9
5 7 9 10
5 5 7 4
5 5 7 5
5 5 7 6
5 5 7 7
5 5 7 8
5 7 7 4
5 7 7 5
5 7 7 6
5 7 7 7
5 7 7 8
7 7 7 6
7 7 7 7
7 7 7 8
10 10 10 8
7 8 10 9
10 10 10 10
9 9 9 10
'''
