test_number = 0
with open('a_large.in', 'r') as f, open('a.out', 'w') as g:
    for line in f:
        if test_number == 0:
            test_number += 1
            continue
        N = int(line.rstrip())
        if N == 0:
            g.write('Case #' + str(test_number) + ': INSOMNIA' + '\n')
            test_number += 1
            continue
        cur = N
        print(N)
        numbers = set(str(cur))
        while len(numbers) != 10:
            cur += N
            numbers.update(set(str(cur)))
        g.write('Case #' + str(test_number) + ': ' + str(cur) + '\n')
        test_number += 1
