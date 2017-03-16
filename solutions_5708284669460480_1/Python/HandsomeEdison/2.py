if __name__ == "__main__":
    T = int(raw_input())
    for _ in range(T):
        k, l, s = map(int, raw_input().split())
        keyboard = raw_input()
        target = raw_input()
        ks = set(x for x in keyboard)
        ts = set(x for x in target)
        if not ((ts & ks) == ts):
            print 'Case #{}: {}'.format(_ + 1, 0.0)
            continue
        overlap = l
        for i in range(1, l):
            if target[i:] == target[:-i]:
                overlap = i
                break
        ans = (s - l) / overlap + 1
        ks = {}
        for x in keyboard:
            if x not in ks:
                ks[x] = 0
            ks[x] += 1
        dp = []
        for i in range(s):
            dp.append([0] * l)
            for j in range(min(i + 1, l)):
                if i == 0 or j == 0:
                    dp[i][j] = float(ks[target[j]]) / k
                else:
                    dp[i][j] = dp[i - 1][j - 1] * float(ks[target[j]]) / k
        for i in range(l - 1, s):
            ans -= dp[i][l - 1]
        print 'Case #{}: {}'.format(_ + 1, ans)
