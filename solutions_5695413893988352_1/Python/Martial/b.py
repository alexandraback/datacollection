import sys
# sys.stdin = open('b1.in')
sys.stdin = open('B-large.in')
sys.stdout = open('out-large.txt', 'w')


def solve_it(u, v):
    d = len(u)

    equal_possible = True
    for i in range(d):
        if u[i].isdigit() and v[i].isdigit() and u[i] != v[i]:
            equal_possible = False
    if equal_possible:
        lu = list(u)
        lv = list(v)
        for i in range(d):
            digit = '0'
            if lu[i].isdigit():
                digit = lu[i]
            if lv[i].isdigit():
                digit = lv[i]
            lu[i] = digit
            lv[i] = digit
        u = ''.join(lu)
        v = ''.join(lv)
        return 0, int(u), int(v)

    lu = list(u)
    lu.reverse()
    u = ''.join(lu)
    lv = list(v)
    lv.reverse()
    v = ''.join(lv)

    i0 = d - 1
    while u[i0] == '?' or v[i0] == '?':
        i0 -= 1
    best = 10 ** 30
    bestC = 10 ** 30
    bestJ = 10 ** 30

    # C > J
    for i in range(d - 1, i0 - 1, -1):
        if u[i] == '0' or v[i] == '9':
            continue
        if u[i].isdigit() and v[i].isdigit() and u[i] < v[i]:
            continue
        a = list(u)
        b = list(v)

        # j > i
        for j in range(d - 1, i, -1):
            digit = '0'
            if u[j].isdigit():
                digit = u[j]
            if v[j].isdigit():
                digit = v[j]
            a[j] = digit
            b[j] = digit

        # j == i
        above = u[i]
        below = v[i]
        if above == '?' and below == '?':
            a[i] = '1'
            b[i] = '0'
        if above == '?' and below.isdigit():
            a[i] = str(int(below) + 1)
            b[i] = v[i]
        if above.isdigit() and below == '?':
            a[i] = above
            b[i] = str(int(above) - 1)
        if above.isdigit() and below.isdigit():
            a[i] = u[i]
            b[i] = v[i]

        # j < i
        for j in range(i - 1, -1, -1):
            if u[j] == '?':
                a[j] = '0'
            if v[j] == '?':
                b[j] = '9'
        a.reverse()
        b.reverse()
        C = int(''.join(a))
        J = int(''.join(b))
        if abs(C - J) <= best:
            if abs(C - J) < best:
                best = abs(C - J)
                bestC = C
                bestJ = J
            else:
                if C <= bestC:
                    if C < bestC:
                        bestC = C
                        bestJ = J
                    else:
                        if J < bestJ:
                            bestJ = J

    # C < J
    for i in range(d - 1, i0 - 1, -1):
        if u[i] == '9' or v[i] == '0':
            continue
        if u[i].isdigit() and v[i].isdigit() and u[i] > v[i]:
            continue
        a = list(u)
        b = list(v)

        # j > i
        for j in range(d - 1, i, -1):
            digit = '0'
            if u[j].isdigit():
                digit = u[j]
            if v[j].isdigit():
                digit = v[j]
            a[j] = digit
            b[j] = digit

        # j == i
        below = u[i]
        above = v[i]
        if above == '?' and below == '?':
            a[i] = '0'
            b[i] = '1'
        if above == '?' and below.isdigit():
            a[i] = below
            b[i] = str(int(below) + 1)
        if above.isdigit() and below == '?':
            a[i] = str(int(above) - 1)
            b[i] = above
        if above.isdigit() and below.isdigit():
            a[i] = u[i]
            b[i] = v[i]

        # j < i
        for j in range(i - 1, -1, -1):
            if u[j] == '?':
                a[j] = '9'
            if v[j] == '?':
                b[j] = '0'
        a.reverse()
        b.reverse()
        C = int(''.join(a))
        J = int(''.join(b))
        if abs(C - J) <= best:
            if abs(C - J) < best:
                best = abs(C - J)
                bestC = C
                bestJ = J
            else:
                if C <= bestC:
                    if C < bestC:
                        bestC = C
                        bestJ = J
                    else:
                        if J < bestJ:
                            bestJ = J

    return best, bestC, bestJ


def main():

    n_cases = int(input())
    for test_case in range(1, n_cases + 1):
        u, v = input().split()
        d = len(u)
        print(test_case, file=sys.stderr, end=' ')
        best, bestC, bestJ = solve_it(u, v)
        res = str(bestC).zfill(d) + ' ' + str(bestJ).zfill(d)
        print('Case #' + str(test_case) + ':', res)

    print(file=sys.stderr)

if __name__ == '__main__':
    main()