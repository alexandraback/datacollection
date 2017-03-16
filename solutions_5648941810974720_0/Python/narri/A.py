import sys

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next

STRINGS = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

IDENTS = []
for ss in STRINGS:
    dd = dict()
    for ch in ss:
        if ch in dd:
            dd[ch] += 1
        else:
            dd[ch] = 1
    IDENTS.append(dd)

def solve(s):
    counts = dict()
    for ch in s:
        if ch in counts:
            counts[ch] += 1
        else:
            counts[ch] = 1

    def del_counts(ct, ident):
        if ct == 0:
            return
        for k, v in ident.iteritems():
            counts[k] -= v*ct
            assert counts[k] >= 0
    ans = [0] * 10
    ans[0] = counts.get('Z', 0)
    del_counts(ans[0], IDENTS[0])
    ans[2] = counts.get('W', 0)
    del_counts(ans[2], IDENTS[2])
    ans[4] = counts.get('U', 0)
    del_counts(ans[4], IDENTS[4])
    ans[5] = counts.get('F', 0)
    del_counts(ans[5], IDENTS[5])
    ans[6] = counts.get('X', 0)
    del_counts(ans[6], IDENTS[6])
    ans[7] = counts.get('V', 0)
    del_counts(ans[7], IDENTS[7])
    ans[8] = counts.get('G', 0)
    del_counts(ans[8], IDENTS[8])
    ans[3] = counts.get('H', 0)
    del_counts(ans[3], IDENTS[3])
    ans[9] = counts.get('I', 0)
    del_counts(ans[9], IDENTS[9])
    ans[1] = counts.get('O', 0)
    del_counts(ans[1], IDENTS[1])
    assert all(counts[k] == 0 for k in counts)
    out = []
    for i, ct in enumerate(ans):
        out.append(chr(i + ord('0')) * ct)
    return ''.join(out)

T = int(cin())
for cn in xrange(1,T+1):
    s = cin()
    print "Case #%d: %s" % (cn, solve(s))


