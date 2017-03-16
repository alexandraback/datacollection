def read_case():
    return raw_input()

def solve(case):
    result = case[0]
    for c in case[1:]:
        if c >= result[0]:
            result = c + result
        else:
            result = result + c
    return result

T = int(raw_input())
for t in range(T):
    case = read_case()
    result = solve(case)
    print "Case #%d: %s" % (t+1, result)
