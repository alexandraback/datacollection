
F = {}

def g(x, b, y) :
    if (x >> b & 1) == 1 and y == 0 :
        return (1 << b) - 1
    return min(x, x ^ (1 << b))

def f(A, B, K, b) :
    if A == 0 or B == 0 :
        return A + B + 1

    global F
    if (A, B, K) in F:
        return F[(A, B, K)]
    ret = 0
    for i in range(2) :
        for j in range(2) :
            if (i & j) <= (K >> b & 1) and i <= (A >> b & 1) and j <= (B >> b & 1) :
                # if b == 2 :
                #     print('x', i, j)
                # print('--', g(A, b, i), g(B, b, j), g(K, b, i & j), f(g(A, b, i), g(B, b, j), g(K, b, i & j), b - 1), i, j, i & j)
                ret += f(g(A, b, i), g(B, b, j), g(K, b, i & j), b - 1)

    # print(A, B, K, ret)
    F[(A, B, K)] = ret
    return ret

# print(f(6, 7, 4, 30))
with open("B-large.in", "r") as fi :
    T = int(fi.readline())
    for T in range(T) :
        A, B, K = map(int, fi.readline().split(' '))
        print("Case #%d: %d" % (T + 1, f(A - 1, B - 1, K - 1, 32)))
