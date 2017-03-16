import sys

sys.stdin = open('B-large.in', 'r')
sys.stdout = open('B-large.out', 'w')

cache = {}


def solve(sx, sy):

    if sx+sy in cache:
        return cache[sx+sy]

    L = len(sx)

    if not L:
        return 0, '', ''

    if sx[0] == '?' and sy[0] == '?':
        diff, x, y = min([
            solve('0' + sx[1:], '1' + sy[1:]),
            solve('1' + sx[1:], '0' + sy[1:]),
            solve('0' + sx[1:], '0' + sy[1:]),
        ])
        cache[sx+sy] = diff, x, y
        return diff, x, y
    elif sx[0] == '?':
        if L == 1:
            return 0, sy[0], sy[0]
        # if sx[1] == '?' or sy[1] == '?':
        #     diff, x, y = solve(sx[1:], sy[1:])
        #     result = diff, sy[0] + x, sy[0] + y
        #     cache[sx+sy] = result
        #     return result
        # if int(sx[1]) - int(sy[1]) > 5:
        #     result = solve(str(max(0, int(sy[0]) - 1)) + sx[1:], sy)
        #     cache[sx+sy] = result
        #     return result
        # if int(sx[1]) - int(sy[1]) < -5:
        #     result = solve(str(min(9, int(sy[0]) + 1)) + sx[1:], sy)
        #     cache[sx+sy] = result
        #     return result
        # if -4 < int(sx[1]) - int(sy[1]) < 4:
        #     result = solve(sy[0] + sx[1:], sy)
        #     cache[sx+sy] = result
        #     return result
        diff, x, y = min([
            solve(str(max(0, int(sy[0]) - 1)) + sx[1:], sy),
            solve(str(min(9, int(sy[0]) + 1)) + sx[1:], sy),
            solve(sy[0] + sx[1:], sy),
        ])
        result = diff, x, y
        cache[sx+sy] = result
        return result

    elif sy[0] == '?':
        diff, y, x = solve(sy, sx)
        result = diff, x, y
        cache[sx+sy] = result
        return result
    elif sx[0] == sy[0]:
        diff, x, y = solve(sx[1:], sy[1:])
        result = diff, sx[0] + x, sy[0] + y
        cache[sx+sy] = result
        return result
    else:
        # 两个都是数字而且不相等
        gt = sx[0] > sy[0]
        x = ''
        y = ''
        for a, b in zip(sx, sy):
            if a == '?':
                x += '0' if gt else '9'
            else:
                x += a
            if b == '?':
                y += '9' if gt else '0'
            else:
                y += b
        result = abs(int(x) - int(y)), x, y
        cache[sx+sy] = result
        return result


for t in range(1, int(input()) + 1):

    a, b = input().strip().split()

    diff, x, y = solve(a, b)

    print('Case #%s: %s %s' % (t, x, y))
