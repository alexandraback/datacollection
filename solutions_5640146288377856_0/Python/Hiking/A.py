#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

f_input = open(sys.argv[1])
problems = int(f_input.readline().rstrip())
for probnum in xrange(1, problems+1):
    R, C, W = map(int, f_input.readline().rstrip().split())


    turn = 0
    #1 目的のROW以外潰す
    for _r in xrange(R-1):
        covered = 0
        while covered <= (C-W):
            covered += (W*2-1)
            turn += 1

    #2 目的のROWで端から攻める
    covered = 0
    while covered <= (C-W):
        covered += W
        turn += 1
    # 最後の戦略は考えなおす
    covered -= W
    turn -= 1
    # print ""
    # print "====================="
    # print "C: {}, W: {}".format(C, W)
    # print "covered: {}".format(covered)

    #3 追い詰める
    if C-covered == W: #もう選択の余地がない
        turn += W
    elif C-covered <= W*2: #次の一発が絶対当たる
        turn += 1 #左端からW+1のところに打つ
        turn += W #沈めるまで打つ
    else: # W*2-1 + W残ってる
        turn += 1 #どこにうってもハズレと言われるので、W*2-1にうつ
        turn += 1 #残り区間の左端からW+1のところに打つ
        turn += W #沈めるまで打つ


    print("Case #{}: {}".format(probnum, turn))
