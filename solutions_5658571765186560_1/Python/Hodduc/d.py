# -*- coding:utf-8 -*-
for T in range(1, input()+1):
    X, R, C = map(int, raw_input().split())
    if (R * C) % X != 0: # 걍 못막음
        print "Case #%d: RICHARD" % T
        continue
    if X == 1: # 걍 채움
        print "Case #%d: GABRIEL" % T
        continue
    if X >= 7: # 중간에 구멍있게 주면 못막음
        print "Case #%d: RICHARD" % T
        continue
    if R < X and C < X: # 1 by X 주면 못막음
        print "Case #%d: RICHARD" % T
        continue
    if X == 2: # 짝수인쪽을 기준으로 채우면 항상 막음
        print "Case #%d: GABRIEL" % T
        continue

    if X == 3: # 2종류가 가능함 (일직선, ㄴ자)
        if R == 1 or C == 1: #ㄴ자
            print "Case #%d: RICHARD" % T
            continue
        else:
            print "Case #%d: GABRIEL" % T
            continue
    if X == 4:
        # 4,1 / 4,2 / 4,3 / 4,4
        # 4,1 : 네모줌 -> 리차드승
        # 4,2 : ㅗ 자 방법없음 -> 리차드승
        # 4,3 : 가브리엘 승
        # 4,4 : 걍 가브리엘 승
        # 한쪽 홀수, 나머지 4의배수 => 1자로 채우므로 가브리엘 승
        # 양쪽다 4n+2꼴이면 => 4*4로 채우고 네모랑 1자로 마무리할수 있음 : 가브
        # 승
        if R == 1 or C == 1: # 네모
            print "Case #%d: RICHARD" % T
            continue
        elif R == 2 or C == 2: # ㅗ자
            print "Case #%d: RICHARD" % T
            continue
        else:
            print "Case #%d: GABRIEL" % T
            continue
    if X == 5:
        if R >= 5 and C >= 5:
            print "Case #%d: GABRIEL" % T
            continue
        if R == 1 or C == 1:
            print "Case #%d: RICHARD" % T
            continue
        if R == 2 or C == 2:  # ㄴ자 주면 못막음
            print "Case #%d: RICHARD" % T
            continue
        if R == 3 or C == 3: # W자 주면 못막음
            print "Case #%d: RICHARD" % T
            continue
        if R == 4 or C == 4:
            print "Case #%d: GABRIEL" % T
            continue
        print "Case #%d: GABRIEL" % T
        continue
    if X == 6:
        if R >= 6 and C >= 6:
            print "Case #%d: GABRIEL" % T
            continue
        if R == 1 or C == 1:
            print "Case #%d: RICHARD" % T
            continue
        if R == 2 or C == 2:  # W자 주면 못막음
            print "Case #%d: RICHARD" % T
            continue
        if R == 3 or C == 3: # 1-4-1자 주면 못막음
            print "Case #%d: RICHARD" % T
            continue
        print "Case #%d: GABRIEL" % T
        continue
