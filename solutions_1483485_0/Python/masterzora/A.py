# A.py

import sys
import os

dictionary = {'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q', ' ': ' '}

def main():
    s = map(lambda X: X[:-1], sys.stdin.readlines())
    os.close(0)

    N = int(s[0])
    s = s[1:]

    for i in range(N):
        print "Case #%s: %s" % (i + 1, trans(s[i]))

def trans(text):
    out = ''
    for i in text:
        out += dictionary[i]

    return out

if __name__ == "__main__":
    main()
