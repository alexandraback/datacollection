from collections import deque

def get_recycled_count(line):
    a, b = line.split()
    recycled_count = 0
    for n in range(int(a), int(b)+1):
        nstr = str(n)
        q = deque(nstr)
        recycled = set()
        for _ in range(len(q)-1):
            q.rotate()
            m = ''.join(q)
            if nstr < m <= b:
                recycled.add(m)

        recycled_count += len(recycled)

    return recycled_count

def file_handler(f):
    for i in range(int(f.readline())):
        yield "Case #%s: %s" % (i+1, get_recycled_count(f.readline()))

import sys
for line in file_handler(sys.stdin):
    print line
