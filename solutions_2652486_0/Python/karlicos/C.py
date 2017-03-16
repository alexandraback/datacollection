from math import *
from sys import stdin, stdout
from itertools import product

# print(pi)

inp = stdin.readlines()

tests = int(inp[0])
inp = inp[1:]


def calc(r, count):
    return (2 * (2 * r + 1) + (count - 1) * 4) * count // 2

curline = 0

for test in range(tests):
    print("Case #{}:".format(test + 1))
    [r, n, m, k] = map(int, inp[curline].split())
    curline += 1
    for i in range(r):
        s = list(map(int, inp[curline].split()))
        curline += 1
        s.sort()
        # print(s)
        bestseq = None
        bestres = None
        for guess in product(range(2, m + 1), repeat = n):
            prods = []
            for mask in product([True, False], repeat = n):
                prod = 1
                for i in range(n):
                    if mask[i]:
                        prod *= guess[i]
                prods.append(prod)
            prods.sort()
            # if guess == (4, 4, 5):
            #     print(s)
            #     print(prods)
            # print(guess)
            # print(prods)
            # if guess == [4, 4, 5]:
                # print(prods)
            cnt = 0
            i = 0
            j = 0
            while i < len(s) and j < len(prods):
                # if guess == (4, 4, 5):
                #     print("i = {}, j = {}".format(i, j))
                if s[i] == prods[j]:
                    i += 1
                    j += 1
                    cnt += 1
                elif s[i] < prods[j]:
                    i += 1
                else:
                    j += 1
            # if guess == (4, 4, 5):
            #     print(cnt)
            # print("Cnt is {}".format(cnt))
            if bestres == None or cnt > bestres:
                bestres = cnt
                bestseq = guess
        for j in range(n):
            stdout.write(str(bestseq[j]))
        stdout.write('\n')
    # print(guess)

