#!/usr/bin/env python
import sys

mapping = {
    'a' : 'y',
    'o' : 'e',
    'z' : 'q',
    'q' : 'z',
}

samples = {
    'ejp mysljylc kd kxveddknmc re jsicpdrysi' : 'our language is impossible to understand',
    'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd' : 'there are twenty six factorial possibilities',
    'de kr kd eoya kw aej tysr re ujdr lkgc jv' : 'so it is okay if you want to just give up',
}

for trans, orig in samples.items():
    for i in range(len(trans)):
        if orig[i].isalpha() and not orig[i] in mapping:
            mapping[orig[i]] = trans[i]

reversed_mapping = dict([(b,a) for a,b in mapping.items()])

def main():
    data = sys.stdin.read().split('\n')
    p = int(data.pop(0))

    for problem in range(1, p + 1):
        l = data.pop(0)
        res = ""
        for c in l:
            res += reversed_mapping.get(c, " ")
        print "Case #%d: %s" % (problem, res)


if __name__ == '__main__':
    main()
