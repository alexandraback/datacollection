#!/usr/bin/env python

import sys

def main():
    known = {
        "y": "a",
        "e": "o",
        "q": "z",
        "ejp mysljylc kd kxveddknmc re jsicpdrysi":
            "our language is impossible to understand",
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd":
            "there are twenty six factorial possibilities",
        "de kr kd eoya kw aej tysr re ujdr lkgc jv":
            "so it is okay if you want to just give up"
        }

    chars = {}
    for crypt, init in known.iteritems():
        assert len(crypt) == len(init)
        for i in range(len(crypt)):
            if crypt[i] not in chars:
                chars[crypt[i]] = init[i]
            assert chars[crypt[i]] == init[i]

    # print chars
    # We see that 'z' is missing. Only letter left is 'q'
    chars['z'] = 'q'

    input = sys.stdin
    T = int(input.readline())
    for t in range(T):
        crypt = input.readline().strip()
        init = []
        for i in range(len(crypt)):
            init.append(chars[crypt[i]])
        init = "".join(init)
        print "Case #%d: %s" % (t + 1, init)

    return 0

if __name__ == "__main__":
    main()
