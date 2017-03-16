file = open('A-small-attempt0.in')
for tc in range(1, int(file.readline())+1):
    r, t = [int(w) for w in file.readline().split()]
    total, rings = 0, 0
    while (True):
        total += pow((r + 1), 2) - pow(r, 2)
        if total<=t:
            rings += 1
        else:
            break
        r += 2
    print ('Case #{0}: {1}'.format(tc, rings))
