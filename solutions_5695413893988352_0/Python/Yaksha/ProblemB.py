import logging
from logging import debug as d
from itertools import product

logging.basicConfig(level=logging.DEBUG, format=('%(funcName)s(%(lineno)d):  %(message)s'))

def p(**kwargs):
    printstr = ''
    for (key, var) in kwargs.items():
        printstr += ("%s=%s\t" % (key, var))

    return printstr


def doSolve(filename, solver, log=False):
    with open(filename) as infile:
        with open(filename + ".out", 'w') as outfile:
            numCases = int(infile.readline())

            for i in range(numCases):
                inputs = parseTestCase(infile)
                result = solver(*inputs)
                if log:
                    print(inputs)
                    print(result)
                    print(" ")

                outfile.write("Case #%d: %s\n" % (i + 1, str(result)))


###=================================== =END TEMPLATE
# logging: d(p(varname=var, varname=var))


def parseTestCase(file):
    prob = file.readline().strip()
    prob = prob.split()
    return (prob[0], prob[1])

def solver(num1, num2):
    n1d = []
    n2d = []

    for x in num1:
        if x == "?":
            n1d.append("0123456789")
        else:
            n1d.append(x)

    for x in num2:
        if x == "?":
            n2d.append("0123456789")
        else:
            n2d.append(x)

    n1s = map(''.join, product(*n1d))
    n2s = map(''.join, product(*n2d))

    n1s = [int(x) for x in n1s]
    n2s = [int(x) for x in n2s]

    diff = 1000
    n1min = 1000
    n2min = 1000
    for n1 in n1s:
        for n2 in n2s:
            newdiff = abs(n1 - n2)
            if newdiff == 0:
                i = 0
            if diff == newdiff:
                if n1min == n1:
                    if n2 < n2min:
                        n2min = n2
                        n1min = n1
                        diff = newdiff
                elif n1 < n1min:
                    n2min = n2
                    n1min = n1
                    diff = newdiff
            elif newdiff < diff:
                n2min = n2
                n1min = n1
                diff = newdiff

    formatstr = "%0" + str(len(num1)) + "d"
    n1str = formatstr % n1min
    n2str = formatstr % n2min

    return n1str + " " + n2str

    pass

FILENAME = r"B-small-attempt0.in"
doSolve(FILENAME, solver, True)
