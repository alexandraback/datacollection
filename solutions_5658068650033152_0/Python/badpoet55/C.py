def update(t):
    global ans
    if t < ans:
        ans = t

def solve(n, m, k):
    global ans
    ans = k
    for i in range(3, n + 1):
        for j in range(3, m + 1):
            rst = i * j
            rest = rst - k
            if rest < 0:
                continue
            if rest <= 4:
                update(i + i + j + j - 4 - rest)

    return ans
def main():
    tc = input()
    for tid in range(1, tc + 1):
        n, m, k = map(int, raw_input().split(" "))
        ans = solve(n, m, k)
        print "Case #%d: %d" % (tid, ans)

if __name__ == "__main__":
    main()
