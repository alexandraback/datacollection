import string
n = input()
for t in xrange(n):
    st = raw_input()
    count = dict.fromkeys(string.ascii_uppercase, 0)
    ans = [0] * 10
    for s in st:
        if s not in count:
            count[s] = 1
        else:
            count[s] += 1
    ans[0] += count['Z']
    count['E'] -= count['Z']
    count['R'] -= count['Z']
    count['O'] -= count['Z']
    count['Z'] = 0
    ans[4] += count['U']
    count['F'] -= count['U']
    count['O'] -= count['U']
    count['R'] -= count['U']
    count['U'] = 0
    ans[2] += count['W']
    count['O'] -= count['W']
    count['T'] -= count['W']
    count['W'] = 0
    ans[8] += count['G']
    count['E'] -= count['G']
    count['I'] -= count['G']
    count['H'] -= count['G']
    count['T'] -= count['G']
    count['G'] = 0
    ans[6] += count['X']
    count['S'] -= count['X']
    count['I'] -= count['X']
    count['X'] = 0
    ans[1] += count['O']
    count['N'] -= count['O']
    count['E'] -= count['O']
    count['O'] = 0
    ans[3] += count['T']
    count['H'] -= count['T']
    count['R'] -= count['T']
    count['E'] -= count['T']*2
    count['T'] = 0
    ans[5] += count['F']
    count['I'] -= count['F']
    count['V'] -= count['F']
    count['E'] -= count['F']
    count['F'] = 0
    ans[7] += count['V']
    count['S'] -= count['V']
    count['N'] -= count['V']
    count['E'] -= count['V']*2
    count['V'] = 0
    ans[9] = count['I']
    print "Case #%d:"%(t+1),
    ss = ''
    for r,ab in enumerate(ans):
        ss += str(r)*ab
    print ss
    #print count
