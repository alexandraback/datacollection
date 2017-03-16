#
# problemB.py
#

# Import
import sys
sys.dont_write_bytecode = True
sys.path.append('../')
from gcj import Problem
from gcj.utils import Timer

# Parser
def parser(fin):
    N = fin.readInt()
    data = []
    for _ in xrange(2*N-1):
        data.append(fin.readInts())
    return N,data
     
# Solver
def solver(data):
    [N,data] = data
    data.sort()
    print data
    missing = []
    count = {}
    for n in xrange(N):
        for d in data:
            if not d[n] in count:
                count[d[n]] = 0
            count[d[n]] += 1
    for key in count:
        if count[key] % 2 == 1:
            missing.append(key)
    missing.sort()
    print missing
        
    
    return ' '.join(map(str,missing))

# Main
if __name__ == '__main__':
    with Timer('Problem B'):
        Problem(parser, solver).run()
