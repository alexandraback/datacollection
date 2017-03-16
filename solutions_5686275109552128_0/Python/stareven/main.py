import math

def ReadIn():
    t = int(input())
    for c in range(1, t + 1):
        n = int(input())
        a = [int(x) for x in input().split()]
        yield c, a

def Solve(a):
    # print(a)
    ret = max(a)
    for size in range(ret, 0, -1):
        chunk = 0
        for x in a:
            chunk += math.ceil(x / size) - 1
        ret = min(ret, chunk + size)
    return ret

if __name__ == '__main__':
    for c, a in ReadIn():
        print('Case #%d: %d' % (c, Solve(a)))