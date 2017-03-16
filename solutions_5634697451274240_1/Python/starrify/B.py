# coding: utf8

import sys


def main():
    t = int(sys.stdin.readline())
    for i in range(t):
        stack = sys.stdin.readline().strip()
        count = 0
        while stack:
            stack = stack.rstrip('+')
            if stack:
                stack = ''.join('-' if x == '+' else '+' for x in stack)
                count += 1
        print('Case #%s: %s' % (i + 1, count))


if __name__ == '__main__':
    main()
