# coding: utf8

import sys


def main():
    t = int(sys.stdin.readline())
    for i in range(t):
        n = int(sys.stdin.readline())
        digits = set()
        num_seen = set()
        result = None
        _n = 0
        while True:
            _n += n
            digits.update(set(str(_n)))
            if len(digits) == 10:
                result = _n
                break
            if _n in num_seen:
                result = 'INSOMNIA'
                break
            num_seen.add(_n)
        print 'Case #%s: %s' % (i + 1, result)


if __name__ == '__main__':
    main()
