def get_better(a, b):
    if a is None: return b
    if b is None: return a
    if a[0] < b[0]: return a
    if a[0] > b[0]: return b
    if a[1] < b[1]: return a
    if a[1] > b[1]: return b
    if a[2] < b[2]: return a
    return b

def try_all(C, J):
    best = None
    for i in xrange(len(C)):
        if i == 0:
            currC, currJ = 0, 0
        else:
            currC, currJ = int("".join(C[:i])), int("".join(J[:i]))
        if C[i] == '?' and J[i] == '?':
            if currC < currJ:
                candidates = [['9', '0']]
            elif currC > currJ:
                candidates = [['0', '9']]
            else:
                candidates = [['0', '0'], ['0', '1'], ['1', '0']]
            for candidate in candidates:
                C[i], J[i] = candidate
                best = get_better(try_all(C, J), best)
            C[i], J[i] = '?', '?'
            return best
        if C[i] == '?':
            other = int(J[i])
            if currC < currJ:
                candidates = [9]
            elif currC > currJ:
                candidates = [0]
            else:
                candidates = set([(other+9)%10, other, (other+1)%10])
            for candidate in candidates:
                C[i] = chr(ord('0') + candidate)
                best = get_better(try_all(C, J), best)
            C[i] = '?'
            return best
        if J[i] == '?':
            other = int(C[i])
            if currJ < currC:
                candidates = [9]
            elif currJ > currC:
                candidates = [0]
            else:
                candidates = set([(other+9)%10, other, (other+1)%10])
            for candidate in candidates:
                J[i] = chr(ord('0') + candidate)
                best = get_better(try_all(C, J), best)
            J[i] = '?'
            return best
    C = "".join(C)
    J = "".join(J)
    res = abs(int(C)-int(J))
    return (res, C, J)

with open("b.in") as f:
    t = int(next(f))
    for case in xrange(t):
        C, J = next(f).split(" ")
        C = list(C.strip())
        J = list(J.strip())
        res = try_all(C, J)
        print "Case #{}: {} {}".format(case+1, res[1], res[2])
