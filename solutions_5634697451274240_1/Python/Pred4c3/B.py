T=int(input())
for case_id in range(1,T+1):
    arr=[True if c=='+' else False for c in input()]
    def solve(arr):
        if all(arr):
            return 0
        if not any(arr):
            return 1
        i=-1
        while arr[i-1] == arr[i]:
            i-=1
        return (0 if arr[-1] else 2) + solve(arr[:i])

    ans = solve(arr)
    print('Case #%d: %s' % (case_id, ans))
    import sys
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
