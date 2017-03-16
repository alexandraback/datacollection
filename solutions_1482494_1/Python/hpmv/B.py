T = int(raw_input())
for t in range(T):
    N = int(raw_input())
    games2 = set()
    games1 = set()
    finish = []
    for i in range(N):
        a, b = raw_input().split()
        a, b = int(a), int(b)
        games2.add((i, a,b))
        games1.add((i, a,b))
        
    star = 0
    num = 0

    while star < 2*N:
        lowest2 = min(games2, key = lambda i: i[2])
        if lowest2[2] <= star:
            if lowest2 not in games1:
                star-=1
            else:
                games1.remove(lowest2)
            games2.remove(lowest2)
            
            star+=2
            num+=1
            
        else:
            games = sorted(games1, key=lambda x:-x[2])
            for g in games:
                if g[1] <= star:
                    games1.remove(g)
                    star += 1
                    num+=1
                    
                    break
            else:
                print "Case #"+str(t+1)+": Too Bad"
                break
    if star == 2*N: print "Case #"+str(t+1)+": "+str(num)


    
    

    
