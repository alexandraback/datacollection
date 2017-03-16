import sys

def solve(test):
    curr, n = [int(_) for _ in sys.stdin.readline().strip().split()]
    vec = [int(_) for _ in sys.stdin.readline().strip().split()]
    vec.sort()
    ret = len(vec)
    x = 0
    i = 0
    while i < n:
        while i < n and curr > vec[i]:
            curr += vec[i]
            i += 1
        temp = x + n - i
        if temp < ret:
            ret = temp

        if curr == 1 or i >= n:
            break

        while curr <= vec[i]:
            curr += (curr-1)
            x += 1

    print 'Case #{0}: {1}'.format(test, ret)

def main():
    T = int(sys.stdin.readline().strip())
    for test in range(1, T + 1):
        solve(test)

main()
