import sys


f = open(sys.argv[1])

lines = f.readlines()[1:]


def output(case, result):
    print "Case #%s: %s" % (case + 1, result)


for index, S in enumerate(lines):
    out = []
    for c in S:
        if len(out) == 0:
            out.append(c)
        elif c >= out[0]:
            out.insert(0, c)
        else:
            out.append(c)
    output(index, "".join(out).strip())
