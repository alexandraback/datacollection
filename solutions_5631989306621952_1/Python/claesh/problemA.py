#
# problemA.py
#

# Import
import sys
sys.dont_write_bytecode = True
sys.path.append('../')
from gcj import Problem
from gcj.utils import Timer

# Parser
def parser(fin):
    return fin.readWord()

# Solver
def solver(data):
    data = list(data)
    lastWord = data[0]
    for i in xrange(1,len(data)):
        if ord(data[i]) >= ord(lastWord[0]):
            lastWord = data[i] + lastWord
        else:
            lastWord = lastWord + data[i]
    return lastWord

# Main
if __name__ == '__main__':
    with Timer('Problem A'):
        Problem(parser, solver).run()
