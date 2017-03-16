import math


def result(test):
    c, f, x = test
    max_factory = int(x / c)
    best = max_factory
    for i in range(max_factory + 1)[::-1]:
        if i <= 0:
            best = 0
            break
        a = (x - c) / (2 + (i - 1) * f)
        b = x / (2 + i * f)
        if a > b:
            best = i
            break
    tmp = 0
    for i in range(best):
        tmp += c / (2 + i * f)
    tmp += x / (2 + best * f)
    return round(tmp, 7)


def main():
    tests = {'count': 0, 'test': []}
    with open('B-small-attempt0.in', 'r') as f:
        for i, l in enumerate(f):
            if i == 0:
                tests['count'] = int(l)
            else:
                tests['test'].append([float(j) for j in l.split(' ')])
    with open('B.out', 'wb') as f:
        for k, i in enumerate(tests['test']):
            f.write("Case #%d: %f\n" % ((k + 1), result(i)))


if __name__ == '__main__':
    main()

"""
4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0
"""
