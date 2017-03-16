from util import *
import math

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in range(num):
        D = int(r.next())
        P = map(int, r.next().split(" "))

        pMap = [0] * 1001 # map from number of pancakes to number of plates
        pMax = 0
        for Pi in P:
            if Pi > pMax:
                pMax = Pi
            pMap[Pi] += 1

        minTime = pMax
        for i in range(1, pMax + 1):
            t = i
            for j in range(1, pMax + 1):
                print t
                t += pMap[j] * int(math.ceil(j / float(i)) - 1)
                if t >= minTime:
                    break
            if t < minTime:
                minTime = t

        ans.append(minTime)

    write("output", ans)

def getMaxTwo(Pmap):
    m = 0
    for i in range(1000, -1, -1):
        if Pmap[i] > 0:
            if m > 0:
                return (m, i)
            else:
                m = i
    return (m, 0)

if __name__ == '__main__':
    main()
