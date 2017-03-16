def solve(a, b, ps):
    p = reduce(lambda x, y: x * y, ps[:a])
    case1 = p * (b - a + 1)
    case1 += (1.0 - p) * (b - a + 1 + b + 1)

    p = reduce(lambda x, y: x * y, ps[:(a - 1)]) if a > 1 else 0.0
    case2 = p * (1 + b - a + 1 + 1)
    case2 += (1.0 - p) * (1 + b - a + 1 + 1 + b + 1)

    p = reduce(lambda x, y: x * y, ps[:(a - 2)]) if a > 2 else 0.0
    case3 = p * (2 + b - a + 1 + 2)
    case3 += (1.0 - p) * (2 + b - a + 1 + 2 + b + 1)

    case4 = 1.0 + b + 1.0

    return min(case1, case2, case3, case4)


with open('input.txt') as input, open('output.txt', 'w') as output:
    for i in range(int(input.readline())):
        a, b = map(int, input.readline().split())
        p = map(float, input.readline().split())
        solution = solve(a, b, p)

        output.write('Case #%d: %.6f\n' % (i + 1, solution))