import fileinput
import sys

TABLE = {
    ('1', '1'): (1, '1'),
    ('1', 'i'): (1, 'i'),
    ('1', 'j'): (1, 'j'),
    ('1', 'k'): (1, 'k'),
    ('i', '1'): (1, 'i'),
    ('i', 'i'): (-1, '1'),
    ('i', 'j'): (1, 'k'),
    ('i', 'k'): (-1, 'j'),
    ('j', '1'): (1, 'j'),
    ('j', 'i'): (-1, 'k'),
    ('j', 'j'): (-1, '1'),
    ('j', 'k'): (1, 'i'),
    ('k', '1'): (1, 'k'),
    ('k', 'i'): (1, 'j'),
    ('k', 'j'): (-1, 'i'),
    ('k', 'k'): (-1, '1')
}
IJK = (-1, '1')
I = (1, 'i')
K = (1, 'k')

def mult_val(a, b):
    coef_a, v_a = a
    coef_b, v_b = b
    coef_c, v_c = TABLE[(v_a, v_b)]
    return (coef_a * coef_b * coef_c, v_c)

def valrep(v, rep):
    coef, ans = v
    if rep % 2 == 0:
        coef = abs(coef)
    if ans != '1':
        if rep % 4 == 0:
            ans = '1'
        elif rep % 4 == 2:
            coef *= -1
            ans = '1'
        elif rep % 4 == 3:
            coef *= -1
    return (coef, ans)

def valrep2(v, rep):
    coef, ans = v
    if rep % 2 == 0:
        coef = 1
    coef2, ans2 = evalexp(ans * (rep % 4))
    return (coef * coef2, ans2)

def evalexp(exp):
    ans = '1'
    coef = 1
    for i in exp:
        nowcoef, ans = TABLE[(ans, i)]
        coef *= nowcoef
    return (coef, ans)

def find(val_l, val_r, exp, left):
    l = 0
    r = len(exp) - 1
    exp_l = val_l
    exp_r = val_r
    while l < r and exp_l != I:
        exp_l = mult_val(exp_l, (1, exp[l]))
        l += 1
    if l >= r and exp_l != I:
        return False
    while 0 < r and exp_r != K:
        exp_r = mult_val((1, exp[r]), exp_r)
        r -= 1
    if r <= 0 and exp_r != K:
        return False
    if left == 1 and l > r:
        return False
    # print l, r, I == mult_val(val_l, evalexp(exp[:l])), K == mult_val(evalexp(exp[(r + 1):]), val_r)
    return True

def solve(rep, exp):
    if (len(exp) * rep <= 2):
        return False
    val = evalexp(exp)
    if valrep(val, rep) != IJK:
        return False
    val_reps = map(lambda r: valrep(val, r), range(0, 4))
    for rep_l in xrange(0, 4):
        for rep_r in xrange(0, 4):
            if rep_l + rep_r < rep:
                if find(val_reps[rep_l], val_reps[rep_r], exp, rep - (rep_l + rep_r)):
                    # print rep_l, rep_r
                    return True
    return False

def main():
    f = fileinput.input()
    count = int(f.readline())
    for i in xrange(1, count + 1):
        rep = int(f.readline().split()[1])
        exp = f.readline()[:-1]
        sys.stderr.write("%d..." % i)
        print("Case #%d: %s" % (i, 'YES' if solve(rep, exp) else 'NO'))
    sys.stderr.write("Done\n")

if __name__ == '__main__':
    main()
