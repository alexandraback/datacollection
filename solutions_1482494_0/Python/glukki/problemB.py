#! /usr/bin/env python
from os import path
import fileinput
import time

def print_timing(func):
    def wrapper(*arg):
        t1 = time.time()
        res = func(*arg)
        t2 = time.time()
        print '%s took %0.3f ms' % (func.func_name, (t2-t1)*1000.0)
        return res
    return wrapper


@print_timing
def run(ns=None):
    score = 0
    com = 0
    st = [0 for n in xrange(len(ns))]
    done = False
    while len(ns):
        nMax = None
        for i in xrange(len(ns)):
            if ns[i][1] <= score:
                nMax = i
                break
            if ns[i][0] <= score and st[i] < 1:
                if (nMax is None) or (ns[i][1] > ns[nMax][1]):
                    nMax = i
        if nMax is None:
            return 'Too Bad'
        else:
#            print '%s %s' % (score, ns[nMax])
            com += 1
            if ns[nMax][1] <= score:
                if not st[nMax]:
                    score += 2
                else:
                    score += 1
                del ns[nMax]
                del st[nMax]
            else:
                score += 1
                st[nMax] = 1
    return com

@print_timing
def main():
    tests = []
    result = []
    nLine = None
    filename = None

    for t in fileinput.input():
        if not fileinput.isfirstline():
            if fileinput.lineno() == nLine:
                nLine = nLine + int(t) + 1
                tests.append([])
            else:

                tests[len(tests)-1].append([int(i) for i in t.split()])
        else:
            filename = fileinput.filename()
            nLine = fileinput.lineno() + 1

    i = 0
    for t in tests:
        i += 1
        s = 'Case #%d: %s' % (i, run(t))
        print s
        result.append(s+"\n")

    with open(''.join((path.splitext(filename)[0], '.out')), 'w') as f:
            f.writelines(result)


if __name__ == '__main__':
    main()
