import sys


def solve( stack ):
    stack = stack.strip() + "+"
    return sum( 1 if stack[k] != stack[k+1] else 0 for k in xrange( len(stack)-1 ) )

if __name__ == "__main__":
    fd = open( sys.argv[1] )
    T = int( fd.readline() )
    for t in xrange(T):
        s = solve( fd.readline() )
        print "Case #%d: %d" % (t+1, s)
    fd.close()

