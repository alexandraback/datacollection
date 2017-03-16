import sys

if sys.argv[1:]:
    infn = sys.argv[1]
    if infn.endswith('.in'):
        outfn = infn[:-3] + '.out'
    elif infn.endswith('.'):
        outfn = infn + 'out'
        infn = infn + 'in'
    else:
        outfn = infn + '.out'
        infn = infn + '.in'
    fin = open(infn)
    fout = open(outfn, 'w')
else:
    fin = sys.stdin
    fout = sys.stdout

def Solve():
    inputs = map(int, fin.readline().split())
    N, S, P = inputs[:3]
    s = inputs[3:]
    if P == 0:
        return N
    if P == 1:
        return len(filter(lambda x: x > 0, s))
    s.sort()
    ans = 0
    for x in s:
        if x < P * 3 - 4:
            pass
        elif x < P * 3 - 2:
            if S > 0:
                ans += 1
                S -= 1
        else:
            ans += 1
    return ans

testNo = int(fin.readline())
for caseId in range(1, testNo + 1):
    print >>fout, 'Case #%d:' % caseId, Solve()
