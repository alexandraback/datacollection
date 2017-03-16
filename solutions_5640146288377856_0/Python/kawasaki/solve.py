T = int(raw_input())
for test_index in xrange(1, T + 1):
    R, C, W = map(int, raw_input().split())

    def f(n):
        if W * 2 <= n:
            o = W + 1
            x = 1 + f(n - W)
            return max(o, x)
        else:
            if W == n:
                return W
            return W + 1
        return f(n - W)
    print 'Case #{}: {}'.format(test_index, f(C) + (R - 1) * (C / W))
