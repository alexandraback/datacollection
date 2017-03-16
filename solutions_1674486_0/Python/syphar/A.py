#!/usr/bin/env python

import sys
import itertools

def tree(classes, i, other):
    ret = set(other)
    ret.add(i)

    for cl in classes[i]:
        #print cl
        ret.add(cl)
        ret.update(tree(classes, cl, ret))

    return ret

def d(classes, i):
    l = len(classes[i])
    if l > 1:
        sets = []
        for cl in classes[i]:
            sets.append(tree(classes, cl, set()))

        for x in itertools.combinations(sets, 2):
            if len(x[0].intersection(x[1])) > 0:
                return True

    elif l == 1:
        return d(classes, classes[i][0])
    else:
        return False

def doit(classes):
    for i in range(len(classes)):
        if d(classes, i):
            return True

    return False

def run():
    input = sys.stdin
    output = sys.stdout

    case_count = int(input.readline().strip())

    for caseno in range(case_count):
        class_count = int(input.readline().strip())
        classes = []
        for classno in range(class_count):
            extends = [int(i) for i in input.readline().strip().split()]
            extends = extends[1:extends[0]+1]
            extends = [i - 1 for i in extends]
            classes.append(extends)

        output.write("Case #{0}: {1}\n".format(caseno + 1, "Yes" if doit(classes) else "No"))

if __name__ == '__main__':
    run()
