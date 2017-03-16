def solve(r, t):
    left, right = 0, t
    while left <= right:
        mid = (left + right) // 2
        #print r, t, mid, (2 * r + 2 * mid - 1) * mid
        if (2 * r + 2 * mid - 1) * mid <= t:
            left = mid + 1
        else:
            right = mid - 1
    return right

T = int(raw_input())
for test in range(T):
    line = raw_input()
    key = line.split()
    print "Case #%d: %d" %(test + 1, solve(int(key[0]),int(key[1])))