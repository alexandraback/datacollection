from util import *
import math

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in range(num):
        L, X = map(int, r.next().split(" "))
        line = r.next()
        line = [letterToIndex[l] for l in line]

        chunkProd = multLst(line)

        if exp(chunkProd, X % 4) != -1:
            ans.append("NO")
            continue
        order = 2 if chunkProd == -1 else 4

        X = X if X < 3 * order - 1 else (X % order) + 2 * order
        line = line * X

        iIndex = iterateUntil(line, 0, L * order, 2)
        if iIndex == -1:
            ans.append("NO")
            continue
        jIndex = iterateUntil(line, iIndex + 1, iIndex + 1 + L * order, 3)
        if jIndex == -1:
            ans.append("NO")
            continue

        remainder = (L * X - jIndex - 1) % (L * order)
        if multLst(line[jIndex + 1:jIndex + 1 + remainder]) == 4:
            ans.append("YES")
        else:
            ans.append("NO")

    write("output", ans)

def iterateUntil(line, start, end, goal):
    product = 1
    for i in range(start, end):
        if i >= len(line):
            return -1
        product = mult(product, line[i])
        if product == goal:
            return i
    return -1

# 1: 1
# 2: i
# 3: j
# 4: k
letterToIndex = {"i": 2,
                 "j": 3,
                 "k": 4}
multArray = [[0,0,0,0,0],
             [0,1,2,3,4],
             [0,2,-1,4,-3],
             [0,3,-4,-1,2],
             [0,4,3,-2,-1]]

def mult(a, b):
    sign = int(math.copysign(1, a * b))
    return multArray[abs(a)][abs(b)] * sign

def exp(a, e):
    ans = 1
    for i in range(e):
        ans = mult(ans, a)
    return ans

def multLst(lst):
    product = 1
    for v in lst:
        product = mult(product, v)
    return product

if __name__ == '__main__':
    main()
