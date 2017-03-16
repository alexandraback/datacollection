import sys, math

def isFair(i):
    reverse = 0
    original = i
    while i:
        reverse = 10 * reverse + i % 10
        i = int(i / 10)
    if reverse == original:
        return True
    else:
        return False

def binarySearch(dest, arr, low, hi):
    while low < hi:
        mid = int((low + hi) / 2)
        if arr[mid] <= dest:
            low = mid + 1
        else:
            hi = mid
    return low - 1

if __name__ == '__main__':
    left, right = (1, 10 ** 14)
    # fair = []
    # for i in range(math.ceil(left ** 0.5), int(right ** 0.5) + 1):
    #     if isFair(i) and isFair(i ** 2):
    #         fair.append(i ** 2)
    fair = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]
    count = int(sys.stdin.readline())
    for r in range(1, count + 1):
        accum = 0
        curLeft, curRight = tuple(map(int, sys.stdin.readline().split()))
        indLeft = binarySearch(curLeft, fair, 0, len(fair))
        indRight = binarySearch(curRight, fair, 0, len(fair))
        if 0 <= indLeft and fair[indLeft] == curLeft:
            accum = accum + 1
        print('Case #%d: %d' % (r, accum + indRight - indLeft))

