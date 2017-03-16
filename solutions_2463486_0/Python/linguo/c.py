state = 0
for x in [int(z) for z in open("c-small-attempt0.in").read().split()]:
    if state == 0:
        state = 1
    elif state & 31 == 1:
        if x == 1:
            state += 6
        elif x <= 4:
            state += 5
        elif x <= 9:
            state += 4
        elif x <= 121:
            state += 3
        elif x <= 484:
            state += 2
        else:
            state += 1
    elif state & 31 in range(2,8):
        if x >= 484:
            state += 10
        elif x >= 121:
            state += 9
        elif x >= 9:
            state += 8
        elif x >= 4:
            state += 7
        else:
            state += 6
    if (state & 31) >= 8:
        print "Case #%d: %d" % ((state >> 5) + 1, (state & 31) - 12)
        state = 33 + (state & -32)

