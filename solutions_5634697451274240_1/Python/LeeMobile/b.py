import sys


f = open(sys.argv[1])
lines = f.readlines()[1:]


def output(case, result):
    print "Case #%s: %s" % (case + 1, result)


for index, pancakes in enumerate(lines):
    pancakes = pancakes.strip()
    count = 0
    current = pancakes[0]

    if len(pancakes) == 1 and current == '-':
        output(index, 1)
        continue

    for i, p in enumerate(pancakes):
        if current != p:
            count += 1
            current = p

    if pancakes[-1] == '-':
        count += 1
    output(index, count)
