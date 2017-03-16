from collections import Counter
from collections import defaultdict
import sys

sys.setrecursionlimit(100000)

with open('input.txt', 'r') as input, open('output.txt', 'w') as output:
    tt = int(next(input))
    for test in range(tt):
        s = next(input).replace('\n', '')
        d = defaultdict(int)
        d.update(dict(Counter(s)))
        # print(d)
        numbers = [0] * 10
        z = d['Z']
        numbers[0] = z
        d['Z'] -= z
        d['E'] -= z
        d['R'] -= z
        d['O'] -= z
        x = d['X']
        numbers[6] = x
        d['S'] -= x
        d['I'] -= x
        d['X'] -= x
        s = d['S']
        numbers[7] = s
        d['S'] -= s
        d['E'] -= s
        d['V'] -= s
        d['E'] -= s
        d['N'] -= s
        v = d['V']
        numbers[5] = v
        d['F'] -= v
        d['I'] -= v
        d['V'] -= v
        d['E'] -= v
        f = d['F']
        numbers[4] = f
        d['F'] -= f
        d['O'] -= f
        d['U'] -= f
        d['R'] -= f
        w = d['W']
        numbers[2] = w
        d['T'] -= w
        d['W'] -= w
        d['O'] -= w
        r = d['R']
        numbers[3] = r
        d['T'] -= r
        d['H'] -= r
        d['R'] -= r
        d['E'] -= r
        d['E'] -= r
        t = d['T']
        numbers[8] = t
        d['E'] -= t
        d['I'] -= t
        d['G'] -= t
        d['H'] -= t
        d['T'] -= t
        o = d['O']
        numbers[1] = o
        d['O'] -= o
        d['N'] -= o
        d['E'] -= o
        numbers[9] = d['I']
        str = '0123456789'
        ans = ''
        for i in range(10):
            ans += str[i] * numbers[i]

        output.write('Case #{}: {}\n'.format(test + 1, ''.join(ans)))
