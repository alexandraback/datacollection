from random import randint
T = int(raw_input())

def get_factor(x):
    for f in range(2,100):
        if f < x and x % f == 0:
            return f
    return None

for _case in range(T):
    print 'Case #%d:' % (_case+1)
    n, J = [int(x) for x in raw_input().split()]
    vis = set()
    for _i in range(J):
        ok = False
        while not ok:
            s = [1] + [randint(0,1) for _ in range(n-2)] + [1]
            factors = []

            if str(s) in vis:
                continue
            vis.add(str(s))

            for base in range(2,11):
                v = sum([base**i for i in range(n) if s[i] == 1])
                f = get_factor(v)
                if f is None:
                    break
                factors.append(f)

            if len(factors) < 9:
                continue
            ok = True
            s.reverse()
            sv = ''.join([str(x) for x in s])
            print (sv + " " + " ".join([str(x) for x in factors]))
        