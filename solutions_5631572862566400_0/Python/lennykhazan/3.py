import itertools

T = int(input())

def check(arrangement, bffs):
    # print('Checking: ' + str(arrangement))
    if len(arrangement) == 0:
        # print('Yes (0)')
        return True

    for i in range(len(arrangement)):
        if bffs[arrangement[i]] != arrangement[(i+1) % len(arrangement)] and bffs[arrangement[i]] != arrangement[(i-1) % len(arrangement)]:
            # print('Nope')
            return False

    # print('Yep')
    return True

def build(arr, rem, bff):
    # print('build(' + str(arr))
    if len(rem) > 0:
        rightlink = bff[arr[-1]]
        rightarr = arr
        if rightlink in rem:
            rem.remove(rightlink)
            rightarr = build(arr + [rightlink], rem, bff)
            if len(rightarr) == 0:
                if check(arr, bff):
                    rightarr = arr
                else:
                    rightarr = []

            rem += [rightlink]

        leftlink = bff[arr[0]]
        leftarr = arr
        if leftlink in rem:
            rem.remove(leftlink)
            leftarr = build([leftlink] + arr, rem, bff)
            if len(leftarr) == 0:
                if check(arr, bff):
                    leftarr = arr
                else:
                    leftarr = []

            rem += [leftlink]

        rightinlink = 0
        rightinarr = arr
        for key,val in bff.items():
            if val == arr[-1]:
                rightinlink = key
        if rightinlink in rem:
            rem.remove(rightinlink)
            rightinarr = build(arr + [rightinlink], rem, bff)
            if len(rightinarr) == 0:
                if check(arr, bff):
                    rightinarr = arr
                else:
                    rightinarr = []

            rem += [rightinlink]

        leftinlink = 0
        leftinarr = arr
        for key,val in bff.items():
            if val == arr[0]:
                leftinlink = key
        if leftinlink in rem:
            rem.remove(leftinlink)
            leftinarr = build([leftinlink] + arr, rem, bff)
            if len(leftinarr) == 0:
                if check(arr, bff):
                    leftinarr = arr
                else:
                    leftinarr = []

            rem += [leftinlink]

        if len(leftarr) >= len(rightarr) and len(leftarr) >= len(rightinarr) and len(leftarr) >= len(leftinarr):
            return leftarr
        elif len(rightarr) >= len(leftarr) and len(rightarr) >= len(rightinarr) and len(rightarr) >= len(leftinarr):
            return rightarr
        elif len(leftinarr) >= len(rightarr) and len(leftinarr) >= len(rightinarr) and len(leftinarr) >= len(leftarr):
            return leftinarr
        else:
            return rightinarr
    else:
        if check(arr, bff):
            return arr
        else:
            return []

def solve():
    N = int(input())
    bffs = dict()
    inputs = [int(x) for x in input().split(' ')]

    for i in range(N):
        bffs[i+1] = inputs[i]

    max_len = 0
    for i in range(1, N+1):
        remaining = [x for x in range(1, N+1)]
        remaining.pop(i-1)

        arrangement = build([i], remaining, bffs)
        max_len = max(max_len, len(arrangement))

    return str(max_len)

for t in range(T):
    print('Case #' + str(t+1) + ': ' + solve())
