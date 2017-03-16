digits = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']

from collections import defaultdict


def remove_digit(d, n, h):
    if h <= 0:
        return
    for i in digits[n]:
        d[i] -= h

if __name__ == "__main__":
    t = int(input())
    for case in range(1, t + 1):
        s = input()
        d = defaultdict(lambda: 0)
        for i in s:
            d[i] += 1
        n = [-1] * 10
        n[6] = d['X']
        remove_digit(d, 6, n[6])
        n[0] = d['Z']
        remove_digit(d, 0, n[0])
        n[8] = d['G']
        remove_digit(d, 8, n[8])
        n[4] = d['U']
        remove_digit(d, 4, n[4])
        n[3] = d['R']
        remove_digit(d, 3, n[3])
        n[2] = d['W']
        remove_digit(d, 2, n[2])
        n[1] = d['O']
        remove_digit(d, 1, n[1])
        n[7] = d['S']
        remove_digit(d, 7, n[7])
        n[5] = d['V']
        remove_digit(d, 5, n[5])
        n[9] = d['E']
        remove_digit(d, 9, n[9])

        phone = ''
        for i, a in enumerate(n):
            if a > 0:
                phone += str(i) * a
        print('Case #%d: %s' % (case, phone))
