fp = open("a1s.txt")
fw = open("a1a.txt", 'w')
t = int(fp.readline().strip())
for case in range(t):
    s = fp.readline().strip()
    print(s)
    s = {x:s.count(x) for x in ['E', 'F', 'G', 'H', 'I', 'N', 'O', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Z']}
    print(s)
    t = {x:0 for x in range(10)}
    t[2] = s['W']
    for _ in range(s['W']):
        s['T'] -= 1
        s['O'] -= 1
    print(s)
    t[0] = s['Z']
    for _ in range(s['Z']):
        s['E'] -= 1
        s['R'] -= 1
        s['O'] -= 1
    print(s)
    t[6] = s['X']
    for _ in range(s['X']):
        s['S'] -= 1
        s['I'] -= 1
    t[4] = s['U']
    for _ in range(s['U']):
        s['F'] -= 1
        s['O'] -= 1
        s['R'] -= 1
    t[1] = s['O']
    for _ in range(s['O']):
        s['N'] -= 1
        s['E'] -= 1
    print(s)
    t[3] = s['R']
    for _ in range(s['R']):
        s['T'] -= 1
        s['H'] -= 1
        s['E'] -= 1
        s['E'] -= 1
    t[8] = s['T']
    for _ in range(s['T']):
        s['E'] -= 1
        s['I'] -= 1
        s['G'] -= 1
        s['H'] -= 1
    t[5] = s['F']
    for _ in range(s['F']):
        s['I'] -= 1
        s['V'] -= 1
        s['E'] -= 1
    t[7] = s['V']
    for _ in range(s['V']):
        s['S'] -= 1
        s['E'] -= 1
        s['E'] -= 1
        s['N'] -= 1
    t[9] = s['I']
    for _ in range(s['I']):
        s['N'] -= 1
        s['N'] -= 1
        s['E'] -= 1
    print(t)
    g = ''.join(str(x)*t[x] for x in range(10))
    fw.write("Case #{0}: {1}\n".format(case+1, g))

    
