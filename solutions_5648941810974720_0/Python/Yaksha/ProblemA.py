import logging
from logging import debug as d

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
    astring = file.readline().strip()
    astring = astring.lower()
    return astring

def solver(*args):
    final = {}
    for i in range(10):
        final[i] = 0

    final[0] = args.count('z')
    final[2] = args.count('w')
    final[4] = args.count('u')
    final[6] = args.count('x')
    final[8] = args.count('g')
    final[5] = args.count('f') - final[4]
    final[3] = args.count('h') - final[8]
    final[7] = args.count('s') - final[6]
    final[1] = args.count('o') - (final[0] + final[2] + final[4])
    final[9] = args.count('i') - (final[5] + final[6] + final[8])

    astring = ""
    for i in range(10):
        astring = astring + (str(i) * final[i])

    return astring



FILENAME = r"C:\Users\Yaksha\Downloads\A-small-attempt0.in"
doSolve(FILENAME, solver, True)
