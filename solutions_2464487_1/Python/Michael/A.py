def read_line():
    return raw_input().strip()

def read_words():
        return read_line().split()

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_words() ]

T = read_integer()
for i in range( T ):
    r, t = read_integers()
    a = 2
    b = 2*r - 1
    c = -t
    n = int( ( -b + ( b*b - 4*a*c )**0.5 )/( 2*a ) )
    while n*( 2*n + 2*r - 1 ) < t:
        n += 1
    while n*( 2*n + 2*r - 1 ) > t:
        n -= 1
    print 'Case #%i:' % ( i + 1 ), n

''' 
pi*(r+1)^2 - pi*r^2
pi*(r+3)^2 - pi*(r+2)^2
pi*(r+5)^2 -pi*(r+4)^2
pi*(r+7)^2 -pi*(r+6)^2

pi( 2r + 1 )
pi( 6r + 9 - 4r -4 )
pi( 10r + 25 - 8r - 16 )
pi( 14r + 49 - 12r - 36 )
pi( 18r + 81 - 16r - 64 )

2r + 1
2r + 5
2r + 9
2r + 13
2r + 17

2r + 1
2r + 1 + 4
2r + 1 + 2*4
2r + 1 + 3*4
2r + 1 + 4*4

2rn + n + 2n(n-1)
= n*( 2r + 1 + 2n - 2)
= n*( 2n+ 2r - 1 )

2n^ + ( 2r-1 )*n -t = 0
(1-r) + ( 2r-1 ) = 0'''
