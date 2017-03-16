# Python 3.4

# Codejam, 2014, Round 1C, Problem A

import sys
import pprint
import math

def gcd( aa , bb ) :
    return gcd( bb ,  aa % bb ) if bb else aa
    pass

def main() :
    TT = int( input() )
    for case in range( 1 , 1+TT ) :
        PP , QQ =  ( int( x ) for x in input().split(sep='/') )
        GCD = gcd( PP , QQ )
        PP , QQ = PP // GCD , QQ // GCD
        POWER_OF_TWO = math.log( QQ , 2 )
        if not POWER_OF_TWO.is_integer() :
            print( "Case #{case}: impossible".format( case=case ) )
            continue
        ANSWER = int( POWER_OF_TWO ) - PP.bit_length() + 1
        print( "Case #{case}: {answer}".format( case=case , answer=int(ANSWER) ) )
        pass
    #end-for    
    return 0 # EXIT_SUCCESS
#end-def-main

if __name__ == "__main__" :
    sys.exit( main() )
    #end-if


