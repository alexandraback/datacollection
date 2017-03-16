import sys

def read_line():
    return sys.stdin.readline().rstrip( '\n' )

def read_integer():
    return int( read_line() )

def read_floats():
    return [ float( x ) for x in read_line().split() ]

T = read_integer()
for t in range( T ):
    N = read_integer()
    naomi = sorted( read_floats(), reverse = True )
    ken = sorted( read_floats(), reverse = True )
    d = 0
    n = 0
    for k in ken:
        if naomi[ n ] > k:
            d += 1
            n += 1
    h = 0
    k = 0
    for n in naomi:
        if ken[ k ] > n:
            k += 1
        else:
            h += 1
    print 'Case #%i:' % ( t + 1 ), d, h
