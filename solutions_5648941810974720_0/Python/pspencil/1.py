T = int(raw_input())
for i in range(T):
    print "Case #"+str(i+1)+":",
    s = raw_input()
    d = dict()
    all = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for c in all:
        d[c] = 0
    for c in s:
        if c in d:
            d[c] += 1
        else:
            d[c] = 1
    l = []
    while d['Z']!=0:
        l.append(0)
        d['Z'] -= 1
        d['E'] -= 1
        d['R'] -= 1
        d['O'] -= 1
    while d['W']!=0:
        l.append(2)
        d['T'] -= 1
        d['W'] -= 1
        d['O'] -= 1
    while d['U']!=0:
        l.append(4)
        d['F'] -= 1
        d['O'] -= 1
        d['U'] -= 1
        d['R'] -= 1
    while d['X']!=0:
        l.append(6)
        d['S'] -= 1
        d['I'] -= 1
        d['X'] -= 1
    while d['F']!=0:
        l.append(5)
        d['F'] -= 1
        d['I'] -= 1
        d['V'] -= 1
        d['E'] -= 1
    while d['V'] !=0:
        l.append(7)
        d['S'] -= 1
        d['E'] -= 2
        d['V'] -= 1
        d['N'] -= 1
    while d['G'] != 0:
        l.append(8)
        d['E'] -= 1
        d['I'] -= 1
        d['G'] -= 1
        d['H'] -= 1
        d['T'] -= 1
    while d['O'] != 0:
        l.append(1)
        d['O'] -= 1
        d['N'] -= 1
        d['E'] -= 1
    while d['T'] != 0:
        l.append(3)
        d['T'] -= 1
        d['H'] -= 1
        d['E'] -= 2
        d['R'] -= 1
    while d['I'] != 0:
        l.append(9)
        d['I'] -= 1
    print ''.join(sorted([str(i) for i in l]))
