import functools
import operator
import math

def binom_safe(n, k):
    m = max(n - k, k)
    return functools.reduce(operator.mul, range(m + 1, n + 1), 1) // math.factorial(n - m)

def binom_unsafe(n,k):
    return functools.reduce(lambda a,b: a*(n-b)//(b+1),range(k),1)

binom = binom_safe


def line_to_int_list(file):
    return [int(x) for x in file.readline().strip().split()]

def case0(file):
    # hello
    [n, x, y] = line_to_int_list(file)
    x = abs(x)
    m = x + y
    if y == 0:
        if n >= (m + 1) * (m + 2) // 2:
            return 1
        else:
            return 0
    r = n - m * (m - 1) // 2
    if r <= y:
        return 0
    elif r > m + y:
        return 1
    else:
        return sum(binom(r, i) for i in range(y + 1, min(m, r) + 1)) / (2 ** r)

case = lambda x: str(float(case0(x)))

def cases(in_name, func=None, out_name=None):
    if func is None:
        func = case
    if out_name is None:
        ext = in_name.rindex('.')
        out_name = in_name[:ext] + ".out"
    with open(in_name, 'r') as fin:
        with open(out_name, 'w') as fout:
            ntests = int(fin.readline())
            for i in range(1, ntests + 1):
                fout.write("Case #%i: %s\n" % (i, func(fin)))

Q = 'B'
def run(op, n=0):
    if op == 0:
        cases(Q + "-test.in")
    elif op == 1:
        cases(Q + "-small-attempt0.in")
    elif op == 2:
        cases(Q + "-large.in")

if __name__ == "__main__":
    run(1)