def read_case():
    return input()

from itertools import groupby

def solve(case):
    case = case.rstrip("+")
    return len(list(groupby(case)))

T = int(input())
for t in range(T):
    case = read_case()
    result = solve(case)
    print("Case #%d: %d" % (t+1, result))
