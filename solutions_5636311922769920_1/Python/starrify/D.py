# coding: utf8

import sys


def main():
    t = int(sys.stdin.readline())
    for i in range(t):
        k, c, s = [int(x) for x in sys.stdin.readline().split()]
        picked = []
        to_verify = [x + 1 for x in range(k)]
        while to_verify:
            verify = to_verify[:c]
            to_verify = to_verify[c:]
            pos = 0
            _c = c
            for orig_pos in verify:
                _c -= 1
                pos += (orig_pos - 1) * k ** _c
            pos += 1
            picked.append(pos)
        if len(picked) > s:
            result = 'IMPOSSIBLE'
        else:
            result = ' '.join(str(x) for x in picked)
        print('Case #%s: %s' % (i + 1, result))


if __name__ == '__main__':
    main()
