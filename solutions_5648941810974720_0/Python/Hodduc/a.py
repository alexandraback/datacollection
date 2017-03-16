from collections import defaultdict
T = input()
for t in range(1, T+1):
    s = raw_input()
    d = defaultdict(int)
    for c in s:
        d[c] += 1

    ans = {}
    ans[0] = d['Z']
    ans[2] = d['W']
    ans[4] = d['U']
    ans[6] = d['X']
    ans[8] = d['G']

    ans[5] = d['F'] - ans[4]
    ans[7] = d['S'] - ans[6]
    ans[3] = d['H'] - ans[8]
    ans[1] = d['O'] - ans[0] - ans[2] - ans[4]
    ans[9] = d['I'] - ans[5] - ans[6] - ans[8]

    print "Case #%d: %s" % (t, '0'*ans[0] + '1'*ans[1] + '2'*ans[2] + '3'*ans[3] + '4'*ans[4] + '5'*ans[5] + '6'*ans[6] + '7'*ans[7] + '8'*ans[8] + '9'*ans[9])
