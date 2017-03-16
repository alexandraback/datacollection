
def getList(S,K,C):
    s = ""
    if K==1: return ' 1'
    if C==1:
        for i in range(1,K+1):
            s+= ' ' + str(i)
        return s
    i=1
    j=C
    t=1
    while(i <= K):
        t += (i-1) * K**(j-1)
        i += 1
        j -= 1
        if(j==0):
            s += ' ' + str(t)
            j=C
            t=1
    if(not t==1):
        s += ' ' + str(t)
    return s

t = int(input())
for i in range(1,t+1):
    s = input().split(' ')
    K = int(s[0])
    C = int(s[1])
    S = int(s[2])
    print("Case #{}:{}".format(i,' IMPOSSIBLE' if S<(K/C) else getList(S,K,C)))