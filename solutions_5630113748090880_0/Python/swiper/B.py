from collections import Counter

def read_case():
    N = int(raw_input())
    rows = [map(int, raw_input().split()) for _ in range(2*N-1)]
    return N, rows

def solve(case):
    N, rows = case
    cnt = Counter(sum(rows, []))
    missed = [k for k, v in cnt.items() if v % 2 == 1]
    return sorted(missed)

T = int(raw_input())
for t in range(T):
    case = read_case()
    result = solve(case)
    print "Case #%d: %s" % (t+1, " ".join(map(str, result)))
