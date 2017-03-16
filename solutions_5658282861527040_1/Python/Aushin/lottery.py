def solve(abk):
    a, b, k = abk[0], abk[1], abk[2]
    tests = []
    if k >= a or k >= b:
        return a * b
    else:
        x = k * b #guaranteed
        x += (a - k) * k #other guaranteed
        #x = x - k #repeats
        reset_b = b - 1
        a = a - 1
        k = k - 1
        while k < a:
            b = reset_b
            while k < b:
                t = a & b
                tests.append(t)
                b = b - 1
            a = a - 1
        for n in tests:
            if n <= k:
                x = x + 1
    return str(x)  

with open('c:\\python27\\codejam\\outputs.out', 'w') as w, open('c:\\python27\\codejam\\B-large.in') as r:
    cases = int(r.readline())
    for case in range(1, cases+1):
        abk = [int(x) for x in r.readline().split()]
        w.write('Case #{0}: {1}\n'.format(str(case), solve(abk)))

