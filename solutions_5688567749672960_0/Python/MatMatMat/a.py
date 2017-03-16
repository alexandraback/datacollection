def solve(n):
    distances = {1: 1}
    for i in range(2, n+1):
        if i not in distances or distances[i] > distances[i-1]+1:
            distances[i] = distances[i-1] + 1
        rev = int(''.join(reversed(str(i))))
        if rev not in distances or distances[rev] >= distances[i]+1:
            distances[rev] = distances[i]+1
    return distances[n]

t = int(input())
for case in range(1, t+1):
    n = int(input())
    print('Case #%d: %d' % (case, solve(n)))
