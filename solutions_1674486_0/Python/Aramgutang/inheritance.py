# Usage: python safety.py input.txt > output.txt
import sys

def travel(start, classes, seen):
    seen.append(start)
    if not classes[start]:
        return False
    diamond = False
    for parent in classes[start]:
        if parent in seen:
            return True
        diamond = diamond or travel(parent, classes, seen)
    return diamond

with open(sys.argv[1]) as input:
    for case in xrange(1, int(input.readline().strip())+1):
        classes = [[]]
        for cls in xrange(1, int(input.readline().strip())+1):
            classes.append(map(int, input.readline().strip().split(' ')[1:]))
        diamond = False
        for start in xrange(1, len(classes)):
            diamond = diamond or travel(start, classes, [])
        print 'Case #%s: %s' % (case, 'Yes' if diamond else 'No')