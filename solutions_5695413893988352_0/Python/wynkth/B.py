with open('B-small-attempt0.in', 'rb') as f:
    lines = map(lambda x: x.replace('\n',''), f.readlines())

with open('outB.txt', 'wb') as out:
    for case, numbers in enumerate(lines):
        if case != 0:
            a, b = numbers.split()
            ind_a = [i for i, ltr in enumerate(a) if ltr == '?']
            ind_b = [i for i, ltr in enumerate(b) if ltr == '?']
            a_changes = []
            a_new = [a]
            for i in ind_a:
                a_changes = list(a_new)
                a_new = []
                for j in range(10):
                    for x in a_changes:
                        y = list(x)
                        y[i] = str(j)
                        a_new.append(''.join(y))
            b_changes = []
            b_new = [b]
            for i in ind_b:
                b_changes = list(b_new)
                b_new = []
                for j in range(10):
                    for x in b_changes:
                        y = list(x)
                        y[i] = str(j)
                        b_new.append(''.join(y))
            b_new = sorted(map(int, b_new))
            a_new = sorted(map(int, a_new))
            best_diff = None
            best = None
            for i in a_new:
                for j in b_new:
                    if best_diff is None or abs(i - j) < best_diff:
                        best_diff = abs(i - j)
                        best = (i, j)
            out.write('Case #' + str(case) + ': ' + str(best[0]).zfill(len(a)) + ' ' +
                      str(best[1]).zfill(len(a)) + '\n')






