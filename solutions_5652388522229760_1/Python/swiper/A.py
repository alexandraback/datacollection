def read_case():
    return int(input())

def solve(case):
    N = case
    seen = set(str(case))
    if case == 0:
        return "INSOMNIA"
    while len(seen) < 10:
        case += N
        seen.update(str(case))
    return str(case)

T = int(input())
for t in range(T):
    case = read_case()
    result = solve(case)
    print("Case #%d: %s" % (t+1, result))
