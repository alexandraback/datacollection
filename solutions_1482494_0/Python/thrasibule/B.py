import sys
fh = open(sys.argv[1],"r")
T = int(fh.readline())
for i in xrange(T):
    N = int(fh.readline())
    gameslist = []
    for j in xrange(N):
        a, b = map(int, fh.readline().split() )
        gameslist.append([a,b,False])
    gameslist = sorted(gameslist,key = lambda game: game[1], reverse = True)
    stars = 0
    games = 0
    while len(gameslist):
        flag = False
        #do 2 star games first
        for k in range(len(gameslist)):
            if gameslist[k][1]<=stars and not gameslist[k][2]:
                stars +=2
                gameslist.pop(k)
                games +=1
                flag = True
                break
        if flag:
            continue
        for k in range(len(gameslist)):
            if gameslist[k][1]<=stars:
                if not gameslist[k][2]:
                    print "there is something wrong"
                stars +=1
                gameslist.pop(k)
                games +=1
                flag = True
                break
        if flag:
            continue
        #now check 1 star games
        for k in range(len(gameslist)):
            if gameslist[k][0]<=stars:
                if not gameslist[k][2]:
                    stars +=1
                    games +=1
                    gameslist[k][2] = True
                    flag = True
                    break
        if flag:
            continue
        else:
            break
    if flag:
        print "Case #{0}: {1}".format(i+1, games)
    else:
        print "Case #{0}: Too Bad".format(i+1)
fh.close()
