#!/usr/bin/env python


from sys import stdin

T = int(stdin.readline())

for t in range(T):
    wds = stdin.readline().split()
    N = int(wds[0])

    star = 0
    game = []
    count = 0
    for n in range(N):
        wds = stdin.readline().split()
        game.append([int(wds[0]), int(wds[1])])
        pass

    #print game
    while len(game) > 0:
        mini2_index = 0
        mini2_value = game[0][1]
        for i, g in enumerate(game):
            if mini2_value > g[1]:
                mini2_index = i
                mini2_value = g[1]
                pass
            pass

        if mini2_value <= star:
            #print mini2_index, mini2_value, star, 2
            count += 1
            star += 1
            if game[mini2_index][0] != 5000: star += 1
            del game[mini2_index]
            continue

        mini1_index = -1
        mini1_value = star+1
        mini2_value = 0
        for i, g in enumerate(game):
            if g[0] <= star and mini2_value < g[1]:
                mini1_index = i
                mini1_value = g[0]
                mini2_value = g[1]
                pass
            pass

        if mini1_index >= 0:
            #print mini1_index, mini1_value, star, 1
            count += 1
            star += 1
            game[mini1_index][0] = 5000
            continue

        break

    if len(game) != 0:
        print "Case #%d: Too Bad" % (t+1)
    else:
        print "Case #%d: %d" % ((t+1), count)
