#!/usr/bin/python3


def solve():
    inputList = list(map(int, input().split()))
    k = inputList[0]
    c = inputList[1]
    s = inputList[2]
    res = []
    students = s
    originalTile = 0
    while students > 0:
        studentPos = 0
        for i in range(c-1, -1, -1):
            studentPos += originalTile*(k**i)
            if originalTile == k-1:
                res.append(studentPos)
                return " ".join(map(lambda x: str(x+1), res))

            originalTile += 1
        res.append(studentPos)
        students -= 1
    return 'IMPOSSIBLE'

def main():
    cases = int(input())
    for i in range(0, cases):
        print("Case #%d: %s" % (i+1, solve()))


main()