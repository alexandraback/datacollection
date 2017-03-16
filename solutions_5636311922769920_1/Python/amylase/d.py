def solve(k, c, s):
    """
    >>> solve(1, 1, 1)
    '1'
    >>> solve(2, 1, 1)
    'IMPOSSIBLE'
    """
    student_count = (k + c - 1) / c
    if student_count > s:
        return 'IMPOSSIBLE'
    students = []
    for i in xrange(student_count):
        start, end = c * i, min(c * (i + 1), k)
        dest = 0
        for j, pos in enumerate(xrange(start, end)):
            dest += pow(k, j) * pos
        students.append(dest + 1)
    return ' '.join(map(str, students))


if __name__ == '__main__':
    n = input()
    for i in xrange(n):
        case_num = i + 1
        print "Case #{}: {}".format(case_num, solve(*map(int, raw_input().strip().split())))