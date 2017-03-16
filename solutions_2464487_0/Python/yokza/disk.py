def f(i, R):
    return i * ((i << 1) + R - 1)


def bs(T, R, down, up):
    check = ((up + down) >> 1) + 1

    goal = f(check, R)
    if goal > T:
        return bs(T, R, down, check - 1)

    check += 1
    ugoal = f(check, R)
    if ugoal > T:
        return check - 1
    elif ugoal == T:
        return check
    return bs(T, R, check - 1, up)


def inputer(file_name):
    with open(file_name, 'r') as in_file:
        cases = int(in_file.readline())
        for case_number in xrange(cases):
            r, t = map(long, in_file.readline().split())
            yield r, t, case_number


def solve(file_name, out_file_name):
    out_file = open(out_file_name, 'w')
    for r, t, case in inputer(file_name):
        out_file.write('Case #%d: ' % (case + 1))
        R = (r << 1)
        ans = bs(t, R, 0, t)
        out_file.write('%d\n' % ans)

    out_file.close()


if __name__ == '__main__':
    import sys
    file_name = sys.argv[1]
    out_file_name = sys.argv[2]
    solve(file_name, out_file_name)
