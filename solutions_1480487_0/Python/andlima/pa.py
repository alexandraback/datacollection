def solve(N, S):
    X = sum(S)
    answer = []
    for i, si in enumerate(S):
        # yi = max(100.0 * float(2*X - si * N) / (X * N), 0.0)
        left = 0.0
        right = 1.0
        while right - left > 1e-12:
            yi = (left + right) / 2
            F = si + yi * X
            s = yi
            for j, sj in enumerate(S):
                if i != j:
                    yj = max(0.0, float(F - sj) / X)
                    s += yj
            if s < 1.0:
                left = yi
            else:
                right = yi
        yi = (left + right) / 2
        answer.append(str(100 * yi))
    return answer

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        items = [int(item) for item in raw_input().split(' ')]
        N = items[0]
        S = items[1:]
        answer = solve(N, S)
        print 'Case #%d: %s' % (t + 1, ' '.join(answer))
