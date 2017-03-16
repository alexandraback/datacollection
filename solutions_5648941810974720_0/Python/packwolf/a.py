from collections import Counter

with open('A-small-attempt0.in') as f:
    with open('a.out', 'w') as out:
        cases = f.readline()
        cases = int(cases)
        for i in xrange(1, cases+1):
            line = f.readline()
            c = Counter(line)
            digits = [0 for _ in range(10)]
            # z 0
            # x 6
            # g 8
            # i 5
            # v 7
            # n 9
            # f 4
            # h 3
            # w 2
            # o 1
            for nn, char, number in zip([0, 6, 8, 2, 4, 5, 7, 3, 9, 1], list('ZXGWUFSHIO'), ("ZERO", "SIX", "EIGHT", "TWO", "FOUR", "FIVE", "SEVEN", "THREE", "NINE", "ONE")):
                z = c[char]
                digits[nn] = z
                for cchar in number:
                    c[cchar] -= z
            ret = []
            for dig, count in enumerate(digits):
                ret += str(dig)*count
            res = ''.join(ret)
            print 'Case #{i}: {z}'.format(z=res, i=i)
            out.write('Case #{i}: {z}\n'.format(z=res, i=i))