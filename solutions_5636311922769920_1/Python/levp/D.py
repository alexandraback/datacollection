def solve(k, c):
    ans = []
    i = 0
    cur = 0
    while cur < k:
        cur += 1
        i += 1
        if i == 1:
            pos = cur
        else:
            pos = (pos - 1) * k + cur
        if cur == k and i != c:
            while i != c:
                pos = (pos - 1) * k + cur 
                i += 1
            ans.append(pos)
            return ans
        if i == c:
            ans.append(pos)
            i = 0
    return ans

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        k, c, s = tuple(map(int, input().split()))
        ans = solve(k, c)
        if len(ans) > s:
            print("Case #{0}: IMPOSSIBLE".format(i + 1))
        else:
            print("Case #{0}:".format(i + 1), end='')
            for x in ans:
                print(' ', x, sep='', end='')
            print()

