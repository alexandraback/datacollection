#4
#3 1 5 15 13 11
#3 0 8 23 22 21
#2 1 1 8 0
#6 2 8 29 20 8 18 18 21
#Case #1: 3
#Case #2: 2
#Case #3: 1
#Case #4: 3

def print_game(stars, games, game1, game2):
    print "Stars-", stars
    print "Moves -", games
    print game1
    print game2

f = open('input', 'r')
fw = open('output', 'w')
len = f.readline()
#print len.rstrip()
i=0
for x in range(int(len)):
    i+=1
    line = f.readline()
    line = line.rstrip()
    levels = int(line)
    game1 =[]
    game2=[]
    for j in range(levels):
        line = f.readline()
        line = line.rstrip()
        x = line.split()
        A= int(x[0])  # min1
        B =int(x[1])  # min2
        game1.append (A)
        game2.append(B)
        #game[j][0] = A
        #game[j][1] = B
    game1s = game1[:]
    game2s=game2[:]
    stars = 0
    games =0
    unsolvable = False

    while game2 and not unsolvable:
        if min(game2) <= stars:
            #print 'First', min(game2)
            loc = game2.index(min(game2))
            if game1[loc] != 999999:
                stars +=2
            else:
                stars +=1
            game2.pop(loc)
            game1.pop(loc)
            levels -=1
            games+=1


        elif min(game1) > stars:
            #print 'Second', min(game1)
            unsolvable = True

        else:
            #print 'Third', min(game1), stars
            minmax =0
            for x in range(levels):
                if game1[x]<= stars:
                    if game2[x]>minmax:
                        minmax = game2[x]
                        loc = x
            #print minmax
            game1[loc]=999999
            stars +=1
            games+=1
            #print game1
    #print_game(stars, games, game1s, game2s)

    if levels > 0:
        games = 'Too Bad'
    #print 'Case #'+str(i)+': '+str(games)+'\n'
    fw.write( 'Case #'+str(i)+': '+str(games)+'\n')
