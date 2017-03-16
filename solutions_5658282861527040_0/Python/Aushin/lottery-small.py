def solve(abk):
    ands = []
    a, b, k = abk[0], abk[1], abk[2]
    a = a - 1
    b = b - 1
    reset_b = b
    while a >= 0:
        b = reset_b
        while b >= 0:
            ands.append(a&b)
            b = b - 1
        a = a - 1
    res = 0
    for i in ands:
        if i < k:
            res += 1
    return str(res)  

with open('c:\\python27\\codejam\\outputs.out', 'w') as w, open('c:\\python27\\codejam\\B-small-attempt0.in') as r:
    cases = int(r.readline())
    for case in range(1, cases+1):
        abk = [int(x) for x in r.readline().split()]
        w.write('Case #{0}: {1}\n'.format(str(case), solve(abk)))

