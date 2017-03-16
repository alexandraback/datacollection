def solve():
    K, L, S = map(int, raw_input().split())
    keys = raw_input()
    target = raw_input()

    def dfs(s):
        if len(s) == S:
            c = 0
            for i in xrange(S):
                if s[i:i+L] == target:
                    c += 1
            return [c, 1, c]
        count = [0, 0, 0]
        for k in keys:
            c = dfs(s + k)
            count[0] += c[0]
            count[1] += c[1]
            count[2] = max(count[2], c[2])
        return count

    fit, total, max_ = dfs('')
    return max_ - float(fit) / total

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
