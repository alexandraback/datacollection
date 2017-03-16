import sys

def King_Rush(data_cpy, N):
    data = data_cpy
    games = 0
    stars = 0
    while (stars != (2*N)):
        two_star_games = filter(lambda (x,y,z,n): y <= stars and z<2, data)
        if two_star_games != []:
            poss_two_star_games = filter(lambda (x,y,z,n): z==0, two_star_games)
            if poss_two_star_games != []:
                stars += 2
                games += 1
                a,b,c,d = poss_two_star_games[0]
                data[d] = (a,b,2,d)
            elif (len(two_star_games) - len(poss_two_star_games)) > 0:
                stars += 1
                games += 1
                a,b,c,d = (filter(lambda (x,y,z,n): z==1,two_star_games)).pop()
                data[d] = (a,b,2,d)
        else:
            one_star_games = filter(lambda (x,y,z,n): x <= stars and z==0, data)
            if one_star_games == []:
                return (-1)
            else:
                one_star_games.sort(key=lambda tup: tup[1], reverse = True)
                stars += 1
                games += 1
                a,b,c,d = one_star_games[0]
                data[d] = (a,b,1,d)              
    return games


f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    N = int(f.readline())
    data = []
    for n in range(N):
        a, b = map(int, f.readline().split())
        data.append((a, b, 0, n))
    games = King_Rush(data,N)
    if games == -1:
        print "Case #%d: Too Bad" % (t + 1)
    else:
        print "Case #%d:" % (t + 1), games
