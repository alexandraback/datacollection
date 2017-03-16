# Python 3.2

from common import *

def main(casenum):
    n = readint()
    edges = []
    for i in range(n):
        x, y = readline().split()
        edges.append((x, y))

    xs = set()
    ys = set()
    neigh = {}
    for e in edges:
        a, b = e
        xs.add(a)
        ys.add(b)
        if a not in neigh:
            neigh[a] = []
        neigh[a].append(b)

    xs = list(xs)
    ys = list(ys)

    back = {}
    fore = {}

    count = 0
    good = True
    while good:
        good = False
        back_ = {}

        q = []
        for x in xs:
            if x in fore:
                continue
            q.append(x)

        while len(q) > 0:
            x = q.pop()

            for y in neigh[x]:
                if y in back_:
                    continue
                if y in back:
                    back_[y] = x
                    q.append(back[y])
                else:
                    good = True
                    q = []

                    while x in fore:
                        y_ = fore[x]
                        fore[x] = y
                        back[y] = x
                        y = y_
                        x = back_[y]
                    fore[x] = y
                    back[y] = x
                    count += 1
                    break
    ans = n + count - len(xs) - len(ys)

    writecase(casenum, ans)

run(main)
