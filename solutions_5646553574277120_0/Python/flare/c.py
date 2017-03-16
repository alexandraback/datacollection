import copy
cover = []
def dfs(sum,coinlist,V):
    #print "coinlist",coinlist,sum
    if sum > V:
        return
    cover[sum-1] = 1
    for x in range(len(coinlist)):
        tmplist = copy.deepcopy(coinlist)
        tt = tmplist[x]
        del tmplist[x]
        #print sum
        dfs(sum+tt,tmplist,V)
def checkcover():
    #print cover
    for a in range(len(cover)):
        if cover[a] == 0:
            return a+1;
    return -1

for t in range(int(input())):
    cover = []
    data = raw_input().split()
    C = int(data[0])
    D = int(data[1])
    V = int(data[2])
    for x in range(V):
        cover.append(0)
    coin = []
    da = raw_input().split()
    for x in da:
        coin.append(int(x))
    ans = 0
    for x in range(len(coin)):
        tlist = copy.deepcopy(coin)
        del tlist[x]
        #print tlist

        dfs(coin[x],tlist,V)

    while checkcover() != -1:
        a = checkcover()
       # print cover
        #print a
        #print coin
        ans += 1
        coin.append(a)
        for x in range(len(coin)):
            tlist = copy.deepcopy(coin)
            del tlist[x]
            dfs(coin[x],tlist,V)

    print('Case #%d: %s' % (t + 1, ans))