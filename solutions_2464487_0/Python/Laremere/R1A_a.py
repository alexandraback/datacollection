from decimal import *
getcontext().prec = 100
def quad(b, c):
    return ( -b + ( (b ** 2) + (8 * c) ).sqrt() ) / Decimal(4)
 
def answer(a, b):
    return int( round( quad( Decimal(2 * a - 1), Decimal(b)) - Decimal(0.5) ) )
    
fin = open("A-small.in", "r")
fout = open("small.out", "w")


def next():
    return fin.readline().strip()
    
    
for case in xrange(1, int(next()) + 1):
    print case
    fout.write("Case #" + str(case) + ": ")
    
    args = map( int, next().split(" "))
    
    fout.write(str( answer(*args)))
    
    fout.write('\n')

fin.close()
fout.close()