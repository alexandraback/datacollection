def count(line):
    print(line)
    is_first = int(line[0] == '-')
    was = False
    how = 0
    for x in line:
        if not was:
            if x == '-':
                was = True
                how += 1
        else:
            if x == '+':
                was = False
    print(how)
    return 2 * how - is_first

test_number = 0
with open('b_large.in', 'r') as f, open('b.out', 'w') as g:
    for line in f:
        if test_number == 0:
            test_number += 1
            continue
        ans = count(line.rstrip())
        g.write('Case #' + str(test_number) + ': ' + str(ans) + '\n')
        test_number += 1
