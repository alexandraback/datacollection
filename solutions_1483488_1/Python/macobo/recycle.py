# Recycle.py

from sys import stdin
tens = [10 ** x for x in range(1,7)]

def recycle(x, t):
    # returns -1 on failure
    s = str(x)
    n = s[-t:] + s[:-t]
    return -1 if n[0] == '0' else int(n)

def recycles(x):
    result = []
    for i, t in enumerate(tens):
        if x >= t:
            n = recycle(x, i+1)
            if (n > x):
                result.append(n)
            continue
        break
    return set(result)

#import time
#t = time.time()
recycleMap = dict((x, recycles(x)) for x in range(2000001))
#print time.time() - t

def countRange(lst, x, low, high):
    cnt = 0
    for i in lst:
        if low <= i <= high:
            cnt += 1
    return cnt

def solve(low, high):
    result = 0
    for i in range(low, high+1):
        result += countRange(recycleMap[i], i, low, high)
    return result

def main():
    cases = int(stdin.readline())
    for case in range(1, cases+1):
        a, b = [int(x) for x in stdin.readline().split()]
        result = solve(a, b)
        print 'Case #%d: %d' % (case, result)

if __name__ == "__main__":
#    import time
#    t = time.time()
    main()
#    print time.time() - t
