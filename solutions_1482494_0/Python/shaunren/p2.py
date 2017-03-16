#!/usr/bin/env python

t = int(input())
for case in range(1,t+1):
    n = int(input())
    lvls = []
    played = [[False,False] for _ in range(n)]
    for i in range(n):
        a,b = map(int,input().strip().split())
        lvls.append((b,a,i))

    lvls.sort()

    total = 0
    stars = 0
    while len(lvls):
        for k in range(len(lvls)):
            b,a,i = lvls[k]
            if stars >= b and not played[i][1]:
                #print(b, stars)
                #print('Play L{} Star2'.format(i))
                total += 1
                stars += (1 if played[i][0] else 2)
                played[i][0] = played[i][1] = True
                del lvls[k]
                break
            elif stars >= a and not played[i][0]:
                #print('Play L{} Star1'.format(i))
                total += 1
                stars += 1
                played[i][0] = True
                break
        else:
            total = 'Too Bad'
            break

    print('Case #{}: {}'.format(case, total))
