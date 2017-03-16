import sys


def get_estimate(N, M, nums):
    m = max(nums) 
    result = ""
    while m % 3 == 0:
        m /= 3
        result += "3"
    while m % 5 == 0:
        m /= 5
        result += "5" 
    c2 = 0;
    while m % 2 == 0:
        m /= 2
        c2 += 1
    remaining = N - len(result)
    while remaining > 0:
        if remaining < c2:
            result += "4"
            remaining -= 1
            c2 -= 2
        else:
            result += "2"
            remaining -= 1
            c2 -= 1
    return result

def compute(N, M, x):
    result = ""
    for nums in x:
        values = get_estimate(N, M, nums)
        result += "\n%s" % values
    return result


def parse():
    R, N, M, K = map(int, sys.stdin.readline().strip().split())
    x = []
    for i in xrange(R):
        x.append(map(int, sys.stdin.readline().strip().split()))
    return N, M, x


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    count = 1
    part = 0
    if len(sys.argv) == 3:
        part = int(sys.argv[1])
        count = int(sys.argv[2])
    for i in xrange(T):
        data = parse()
        if i * count >= part * T and i * count < (part + 1) * T:
            result = compute(*data)
            print "Case #%d: %s" % (i + 1, result)
