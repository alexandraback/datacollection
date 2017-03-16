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

srcs = [
        'ejp mysljylc kd kxveddknmc re jsicpdrysi',
        'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
        'de kr kd eoya kw aej tysr re ujdr lkgc jv',
]
dsts = [
        'our language is impossible to understand',
        'there are twenty six factorial possibilities',
        'so it is okay if you want to just give up',
]
mapping = {'q': 'z'}
for src, dst in zip(srcs, dsts):
    for a, b in zip(src, dst):
        if 'a' <= a <= 'z':
            if b < 'a' or b > 'z':
                raise 1
            if mapping.get(a, b) != b:
                raise 2
            mapping[a] = b
alphabet = [chr(x) for x in range(ord('a'), ord('z') + 1)]
src = filter(lambda x: x not in mapping, alphabet)
dst = filter(lambda x: x not in set(mapping.values()), alphabet)
if len(src) > 1 or len(dst) > 1:
    raise 3
if (len(src) > 0) != (len(dst) > 0):
    raise 4
if len(src) == 1:
    mapping[''.join(src)] = ''.join(dst)

def Solve():
    s = fin.readline().strip()
    return ''.join(map(lambda x: mapping[x] if 'a' <= x <= 'z' else x, s))

testNo = int(fin.readline())
for caseId in range(1, testNo + 1):
    print >>fout, 'Case #%d:' % caseId, Solve()
