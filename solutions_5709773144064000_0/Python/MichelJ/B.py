# Qualification Round 2014
# Problem B. Cookie Clicker Alpha
# MichelJ

import sys
import logging
import StringIO
from itertools import chain

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

def solve(c,f,x):
    t = 0.0
    cr = 2.0
    while True:
        t1 = x/cr
        t2 = c/cr + x/(cr+f)
        if t1<t2:
            return t+t1
        t += c/cr
        cr += f
    return 3.1415926535
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        (c,f,x) = map(float,raw_input().split(' '))
        print 'Case #%d: %.7f' % (tc, solve(c,f,x))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
