def mul(q1, q2):
    (a, b, c, d) = q1
    (ap, bp, cp, dp) = q2
    return (a * ap - b * bp - c * cp - d * dp,
            a * bp + b * ap + c * dp - d * cp,
            a * cp - b * dp + c * ap + d * bp,
            a * dp + b * cp - c * bp + d * ap)

def toquat(x):
    if x is 'i':
        return (0, 1, 0, 0)
    elif x is 'j':
        return (0, 0, 1, 0)
    elif x is 'k':
        return (0, 0, 0, 1)

def process(arr, allowed, fun):
    res = [False] * (1 + len(arr))
    avail = set()
    for i in reversed(range(1 + len(arr))):
        if i < len(arr):
            avail = set(map(lambda x: mul(toquat(arr[i]), x), avail))

        if allowed[i]:
            avail.add((1, 0, 0, 0))

        res[i] = fun(avail)
    return res

def solve(arr):
    iter0 = [False] * len(arr) + [True]
    iter1 = process(arr, iter0, lambda x: (0, 0, 0, 1) in x)
    iter2 = process(arr, iter1, lambda x: (0, 0, 1, 0) in x)
    iter3 = process(arr, iter2, lambda x: (0, 1, 0, 0) in x)
    return iter3[0]

def testcase():
    [L, X] = map(int, input().strip().split())
    word = input().strip()
    return solve(word * X)

T = int(input())
for i in range(1, T + 1):
    print("Case #{}: {}".format(i, "YES" if testcase() else "NO"))
