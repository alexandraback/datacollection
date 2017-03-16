import sys, math

def step(start, end):
    cnt = 0
    while start <= end:
        start = start + start - 1
        cnt = cnt + 1
    start = start + end
    return (start, cnt)

if __name__ == '__main__':
    cases = int(sys.stdin.readline())
    for i in range(1, cases + 1):
        (start, otherCount) = map(int, sys.stdin.readline().split())
        other = [int(j) for j in sys.stdin.readline().split()]
        other.sort()
        cnt = 0
        if start == 1:
            cnt = otherCount
        else:
            for j in range(0, otherCount):
                (curStart, curCnt) = step(start, other[j])
                if curCnt < otherCount - j:
                    start = curStart
                    cnt = cnt + curCnt
                else:
                    cnt = cnt + otherCount - j
                    break
        print('Case #%d: %d' % (i, cnt))
