from collections import defaultdict

T = int(raw_input().strip())

for t in range(T):
    A = list(raw_input().strip())
    d = defaultdict(int)
    nums = [0] * 10
    for a in A:
        d[a] += 1
    if d['Z'] > 0:
        nzero = d['Z']
        nums[0] = nzero
        d['Z'] -= nzero
        d['E'] -= nzero
        d['R'] -= nzero
        d['O'] -= nzero
    if d['W'] > 0:
        ntwo = d['W']
        nums[2] = ntwo
        d['T'] -= ntwo
        d['W'] -= ntwo
        d['O'] -= ntwo
    if d['U'] > 0:
        nfour = d['U']
        nums[4] = nfour
        d['F'] -= nfour
        d['O'] -= nfour
        d['U'] -= nfour
        d['R'] -= nfour
    if d['F'] > 0:
        nfive = d['F']
        nums[5] = nfive
        d['F'] -= nfive
        d['I'] -= nfive
        d['V'] -= nfive
        d['E'] -= nfive
    if d['X'] > 0:
        nsix = d['X']
        nums[6] = nsix
        d['S'] -= nsix
        d['I'] -= nsix
        d['X'] -= nsix
    if d['V'] > 0:
        ns = d['V']
        nums[7] = ns
        d['S'] -= ns
        d['E'] -= ns
        d['V'] -= ns
        d['E'] -= ns
        d['N'] -= ns
    if d['G'] > 0:
        ns = d['G']
        nums[8] = ns
        d['E'] -= ns
        d['I'] -= ns
        d['G'] -= ns
        d['H'] -= ns
        d['T'] -= ns
    if d['H'] > 0:
        ns = d['H']
        nums[3] = ns
        d['T'] -= ns
        d['H'] -= ns
        d['R'] -= ns
        d['E'] -= ns
        d['E'] -= ns
    if d['O'] > 0:
        ns = d['O']
        nums[1] = ns
        d['O'] -= ns
        d['N'] -= ns
        d['E'] -= ns
    nums[9] = d['I']
    ans = ''
    for i in range(10):
        ans += str(i) * nums[i]
    print "Case #%d: %s" % (t+1, ans)