#!/usr/bin/env python3.3

def upper_bound(xs, v):
    lb = -1
    ub = len(xs)
    while ub - lb > 1:
        mid = (ub + lb) // 2
        if xs[mid] > v:
            ub = mid
        else:
            lb = mid
    return ub

def war_score(mass1, mass2):
    mass1.sort()
    mass2.sort()
    score = 0
    for x in mass1:
        idx = upper_bound(mass2, x)
   #     print('x = ', x, 'idx = ', idx)
        if idx == len(mass2):
            score += 1
            mass2.pop()
        else:
            mass2.pop(idx)
    return score

def deceit_score(mass1, mass2):
    mass1.sort()
    mass2.sort()
    score = 0
    while len(mass1) > 0:
        if mass1[-1] < mass2[-1]:
            mass1 = mass1[1:]
            mass2 = mass2[:-1]
        else:
            score += 1
            mass1 = mass1[:-1]
            mass2 = mass2[:-1]
    return score

#def deceit_score(mass1, mass2):
#    if len(mass1) == 0:
#        return 0
#    if mass1[-1] < mass2[-1]:
#        return deceit_score(mass1[1:], mass2[:-1])
#    else:
#        return 1 + deceit_score(mass1[:-1], mass2[:-1])

out_file = open('outputD.txt', 'w')
with open('D.in') as f:
    t = int(f.readline())
    for casen in range(1, (t+1)):
        n = int(f.readline())
        mass1 = list(map(lambda x: float(x), f.readline().split()))
        mass2 = list(map(lambda x: float(x), f.readline().split()))
        out_file.write('Case #' + str(casen) + ': '
                       + str(deceit_score(mass1[:], mass2[:])) + ' '
                       + str(war_score(mass1[:], mass2[:])) + '\n')

out_file.close()

        
        
