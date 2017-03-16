
def getList(K):
    s = ""
    for i in range(1,K+1):
        s+= ' ' + str(i)
    return s

t = int(input())
for i in range(1,t+1):
    s = input().split(' ')
    K = int(s[0])
    C = int(s[1])
    S = int(s[2])
    print("Case #{}:{}".format(i,getList(K)))