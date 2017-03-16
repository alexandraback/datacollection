from collections import Counter
from sys import stderr
t = int(input())
def sf(vs):
    for i in range(10):
        for _ in range(vs[i]):
            yield i
for cn in range(t):
    s = raw_input()
    cnt = Counter(s)
    vals = [0 for i in range(10)]
    # Linear programming / Gauss-Jordan reduction
    vals[0] = cnt['Z']
    vals[2] = cnt['W']
    vals[4] = cnt['U']
    vals[6] = cnt['X']
    vals[8] = cnt['G']
    vals[5] = cnt['F'] - vals[4]
    vals[9] = cnt['I'] - vals[5] - vals[6] - vals[8]
    vals[7] = cnt['V'] - vals[5]
    vals[3] = cnt['H'] - vals[8]
    vals[1] = cnt['O'] - vals[0] - vals[2] - vals[4]

    # Santiy checking
    assert vals[3] + vals[8] == cnt['H']
    assert vals[0] + vals[1] + vals[3] + vals[3] + vals[5] + vals[7] + vals[7] + vals[8] + vals[9] == cnt['E'], "Expected %d, got %d: %r %r" % (cnt['E'], vals[0] + vals[1] + vals[3] + vals[3] + vals[5] + vals[7] + vals[7] + vals[8] + vals[9], cnt, vals)
    print("Case #%d: %s" % (cn + 1, ''.join(map(str, sf(vals)))))
