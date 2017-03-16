#!/usr/bin/python3

from common import *

def initmaxsubrange(v):
    n = len(v)
    k = 0
    pow_k = 1
    while pow_k < n:
        k += 1
        pow_k *= 2
    k += 1

    v_memo = [0] * n
    for i in range(n):
        v_memo[i] = [0] * k
        v_memo[i][0] = v[i]
    # v_memo[i][j] holds the maximum of v[i'] for i <= i' < min(i + 2^j, n)

    for j in range(1, k):
        j2 = 2 ** (j - 1)
        for i in range(n):
            a = v_memo[i][j - 1]
            if i + j2 < n:
                a = max (a, v_memo[i + j2][j - 1])
            v_memo[i][j] = a

    return v_memo

# returns the maximum value of v[i'] for i <= i' < j
def maxsubrange(v_memo, i, j):
    a = 0

    if i < 0:
        i = 0
    if j > len(v_memo):
        j = len(v_memo)

    while i < j:
        k = 0
        pow_k = 1
        while pow_k <= (j - i):
            k += 1
            pow_k *= 2
        k -= 1
        pow_k = pow_k // 2

        if v_memo[i][k] > a:
            a = v_memo[i][k]

        i += pow_k

    return a


def testcase(x):
    e, r, n = readintegers()
    v = readintegers()
    # length of v should be n

    if r > e:
        r = e

    v_memo = initmaxsubrange(v)

    # minimum energy at step i: i * r
    # maximum energy at step i: i * r + e

    # espent -- how much energy we've allocated so far
    espent = 0
    i = 0
    j = 0

    gain = 0

    while i < n:
        if j * r <= espent:
            j += 1
            continue
        if i * r + e <= espent:
            i += 1
            continue
        espent_new = min(j * r, i * r + e)
        # print ("Going from %d to %d. (%d, %d) %d" % (i, j, espent, espent_new, maxsubrange(v_memo, i, j)))
        gain += (espent_new - espent) * maxsubrange(v_memo, i, j)
        espent = espent_new

    writeline("Case #%d: %d" % (x, gain))

# xs = [3, 5, 2, 0, 1, 2, 5, 21, 3, 4, 1, 2, 3]
run_tests(testcase)
