#! /usr/bin/env python
__author__ = 'glukki'
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
def run(graph=None):
    inherit = [[] for i in range(len(graph))]
    queue = [i for i in range(len(graph))]
    while len(queue):
        current = queue.pop(0)
        temp = []
        for i in queue:
            for j in graph[i]:
                if j not in temp:
                    temp.append(j)
        if current in temp:
            queue.append(current)
            continue

        for i in graph[current]:
            if current not in inherit[i] and (1 not in [1 for j in inherit[current] if j in inherit[i]]):
                inherit[i].extend(inherit[current])
                inherit[i].append(current)
            else:
                return 'Yes'
    return 'No'


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
                tests[len(tests)-1].append([int(i)-1 for i in t.split()[1:]])
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
