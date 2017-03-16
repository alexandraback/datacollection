from collections import deque
import sys

with open("A-large.in") as f:
    x = f.read().splitlines()

nOfCase = int(x[0])
testCases = x[1:]


file = open('output','w')

for i,a in enumerate(testCases):
    before = a[0]
    d = deque(before)
    for x in a[1:]:
        if x >= before:
            d.appendleft(x)
            before = x
        else:
            d.append(x)
    sys.stdout.write("Case #%d: " % (i+1))
    for elem in d:
        sys.stdout.write(elem)
    sys.stdout.write('\n')


