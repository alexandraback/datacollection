from random import randint


def is_prime(numb):
    for i in range(2, 1000):
        if i * i > numb:
            return True, 0

        if numb % i == 0:
            return False, i

    return True, 0


fi = open('in', 'r')
fo = open('out', 'w')

n = int(fi.readline())
for i in range(n):
    fo.write('Case #%d:\n' % (i + 1))
    n, j = map(int, fi.readline().split())
    for ii in range(j):
        while True:
            s = '1'
            for q in range(n - 2):
                s += str(randint(0, 1))
            s += '1'

            d = []
            # print(s)
            for base in range(2, 11):
                number = int(s, base)
                # print('    ', number)
                y, dd = is_prime(number)
                if y:
                    break

                d.append(dd)
            else:
                fo.write(s + ' ' + ' '.join(map(str, d)) + '\n')
                break
