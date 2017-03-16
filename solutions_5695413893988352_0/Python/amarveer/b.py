import sys

a = set()
ans = [-1,-1,-1]

def solve(C,J,index):
    global ans
    if index == len(C):
        n1 = int(''.join(C))
        n2 = int(''.join(J))
        if ans[0] == -1:
            ans = [n1,n2,abs(n1-n2)]
        elif abs(n1-n2) < ans[2]:
            ans = [n1,n2,abs(n1-n2)]
        elif abs(n1-n2) == ans[2]:
            if ans[0] > n1:
                ans = [n1,n2,abs(n1-n2)]
            elif ans[0] == n1 and ans[1] > n2:
                ans = [n1,n2,abs(n1-n2)]
        #print ans
        return

    l1 = [x     for x in C]
    l2 = [x     for x in J]
    if C[index] == '?' and J[index] == '?':
        for i in xrange(0,10):
            for j in xrange(0,10):
                l1[index] = str(i)
                l2[index] = str(j)
                solve(l1,l2,index+1)
    elif C[index] == '?':
        for i in xrange(0,10):
            l1[index] = str(i)
            solve(l1,J,index+1)
    elif J[index] == '?':
        for i in xrange(0,10):
            l2[index] = str(i)
            solve(C,l2,index+1)

    else:
        solve(C,J,index+1)

for cases in xrange(int(sys.stdin.readline())):
    C, J = (sys.stdin.readline().strip().split())
    C, J = list(C),list(J)
    ans = [-1,-1,-1]
    solve(C,J,0)
    ans[0] = str(ans[0])
    ans[1] = str(ans[1])
    s = '0'*(len(C)-len(ans[0])) + ans [0] + ' '
    s += '0'*(len(C)-len(ans[1])) + ans [1]
    print "Case #%d: %s"%(cases+1,s)
    
