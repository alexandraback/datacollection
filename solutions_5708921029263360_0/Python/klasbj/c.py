import sys
from collections import defaultdict

def combinations(J,P,S):
    for j in range(1,J+1):
        for p in range(1,P+1):
            for s in range(1,S+1):
                yield ((j,p,s), (j,p), (j,s), (p,s))

def solve(j,p,s,k):
    jp, js, ps = defaultdict(int), defaultdict(int), defaultdict(int)
    fs = []
    for f, jp_, js_, ps_ in combinations(j,p,s):
        if jp[jp_] < k and js[js_] < k and ps[ps_] < k:
            fs.append(f)
            jp[jp_] += 1
            js[js_] += 1
            ps[ps_] += 1
    ans = str(len(fs))
    for f in fs:
        ans += '\n' + ' '.join(str(x) for x in f)
    return ans



if __name__ == '__main__':
    lines = ([int(y) for y in x.split()] for x in sys.stdin.readlines()[1:])
    for t, l in enumerate(lines):
        print('Case #{}: {}'.format(t+1, solve(*l)))

