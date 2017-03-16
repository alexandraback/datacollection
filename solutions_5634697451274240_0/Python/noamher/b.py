import os
import sys
from sets import Set


def main():
    if len(sys.argv) != 2:
        print 'usage: a.py <input_file>'
        sys.exit(1)

    with open(sys.argv[1], 'r') as f, open('res', 'w') as out:
        [count] = map(int, f.readline().split())
        for i in xrange(count):
            s = ''.join({'-': '0', '+': '1'}[c] for c in f.readline().split()[0])
            out.write('Case #' + str(i+1) + ': ' + str(min_flips(s)) + '\n')

def min_flips(s):
    c = 0
    for i in xrange(1, len(s)):
        if s[i] != s[i-1]:
            c += 1
    if s[-1] == '0':
        c += 1
    return c


if __name__ == "__main__":
    main()