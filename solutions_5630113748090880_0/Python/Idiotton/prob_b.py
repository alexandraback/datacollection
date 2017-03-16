def f(lines):
    heights = {}

    for line in lines:
        for h in line:
            if (h in heights):
                del heights[h]
            else:
                heights[h] = True

    return sorted(heights.keys())

t = int(input())
for i in range(t):
    n = int(input())
    lines = []

    for j in range(2*n-1):
        lines.append(map(int, input().split()))

    print('Case #' + str(i+1) + ':', ' '.join(map(str,f(lines))))


