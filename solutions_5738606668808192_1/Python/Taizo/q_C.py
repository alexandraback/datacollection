
# -*- coding: cp932 -*-

import sys

#inputFile = "C-small-attempt0.in"
inputFile = "C-large.in"
#inputFile = "B-sample.in"
#f = open(inputFile)
sys.stdout = open(inputFile.replace(".in", ".txt"), 'w')
#tc_num = int(f.readline().rstrip())


def get_divisor(n, table):
    for num in table:
        if num * num >= n:
            break
        if n % num == 0:
            return num
    return 0


def prime_table(n):
    lst = [True for _ in xrange(n + 1)]
    i = 2
    while i * i <= n:
        if lst[i]:
            #sys.stderr.write("try:" + str(i) + "\n")
            j = i + i
            while j <= n:
                lst[j] = False
                j += i
        i += 1

    table = [i for i in xrange(n + 1) if lst[i] and i >= 2]
    return table


def solve(n, j):
    s = (1 << (n - 1)) + 1
    e = (1 << n)
    #table = prime_table(1 << (n-1))
    table = prime_table(1 << 16)
    ansCount = 0
    for v in range(s, e, 2):
        sv = format(v, 'b')
        ans = []
        for base in range(2, 11):
            num = int(sv, base)
            k = get_divisor(num, table)
            if k == 0:
                break
            ans.append(k)

        if len(ans) == 9:
            ansStr = sv
            for k in ans:
                ansStr += " " + str(k)

            print(ansStr)
            ansCount += 1
            if ansCount >= j:
                return


print("Case #1:")
solve(32, 500)
#

