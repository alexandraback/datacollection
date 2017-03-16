import sys

def run(func):
    with open(sys.argv[1]) as handle:
        count = int(handle.readline())
        for x in range(count):
            yield func(handle)

def output(data):
    return '\n'.join('Case #{}: {}'.format(*pair) for pair in enumerate(data, start=1))

def test(func):
    print output(run(func))

def func(handle):
    A, N = map(int, handle.readline().split(' '))
    S = map(int, handle.readline().split(' '))

    ss = sorted(S)

    ops = 0
    eat = 0

    stk = 0
    last = len(ss)

    while ss:
        if A == 1:
            return last
        if A > ss[0]:
            A += ss.pop(0)
            eat += 1
            stk = max(stk - 1, 0)
            if not stk:
                last = ops + len(ss)
        else:
            ops += 1
            stk += 1
            A += A - 1

    return min(last, ops)


test(func)



