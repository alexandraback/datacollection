from util import *

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in range(num):
        X, R, C = map(int, r.next().split(" "))
        if checkVals(X, R, C):
            ans.append("GABRIEL")
        else:
            ans.append("RICHARD")

    write("output", ans)

def checkVals(x, w, h):
    if x >= 7:
        return False
    if x > w and x > h:
        return False
    if (x + 1)/2 > w or (x + 1)/2 > h:
        return False
    if w * h % x != 0:
        return False
    if x == 1 or x == 2 or x == 3:
        return True
    if x == 4:
        if 3 > w or 3 > h:
            return False
        else:
            return True
    if x == 5 or x == 5:
        if 4 > w or 4 > h:
            return False
        else:
            return True
    return True

if __name__ == '__main__':
    main()
