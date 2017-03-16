test_number = 0
with open('d.in', 'r') as f, open('d.out', 'w') as g:
    for line in f:
        if test_number == 0:
            test_number += 1
            continue
        k, c, s = map(int, line.split())
        g.write('Case #' + str(test_number) + ': ' + ' '.join([str(i) for i in range(1, s + 1)]) + '\n')
        test_number += 1
