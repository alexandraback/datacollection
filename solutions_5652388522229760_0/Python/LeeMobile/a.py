import sys


f = open(sys.argv[1])

lines = f.readlines()[1:]


def output(case, result):
    print "Case #%s: %s" % (case + 1, result)


for index, line in enumerate(lines):
    N = int(line)

    if N == 0:
        output(index, "INSOMNIA")
        continue

    numbers = range(10)
    numbers = map(str, numbers)
    i = 1
    #import pdb; pdb.set_trace()
    while(len(numbers) > 0):
        numStr = str(N * i)
        for c in numStr:
            if c in numbers:
                numbers.remove(c)
        i += 1

    output(index, (i -1) * N)
