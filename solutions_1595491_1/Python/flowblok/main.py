def solve(n_suprising, total_points, best_result):
    n_achieved = 0

    for total in total_points:
        k = int(total / 3)
        mod = total % 3

        # try to achieve a best result w/o surpising
        if k >= best_result:
            n_achieved += 1
        elif k == best_result - 1 and mod != 0:
            n_achieved += 1
        # use one of the suprising triples
        elif n_suprising > 0:
            if mod == 0 and k == best_result - 1 and k > 0:
                n_achieved += 1
                n_suprising -= 1
            elif mod == 2 and k == best_result - 2:
                n_achieved += 1
                n_suprising -= 1

    return n_achieved

n = int(raw_input())
for i in xrange(1, n + 1):
    line = map(int, raw_input().split())
    n_googlers = line.pop(0)
    n_suprising = line.pop(0)
    best_result = line.pop(0)
    solution = solve(n_suprising, line, best_result)
    print 'Case #%d:' % i, solution
