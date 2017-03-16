# Python 3.4

# Codejam, 2014, Round Q, Problem D

import itertools
import sys

def main() :
    TT = int( input() )
    for case in range( 1 , 1+TT ) :
        NN = int( input() )
        naomi = set( float( x ) for x in input().split() )
        ken = set( float( x ) for x in input().split() )
        naomi = list( sorted( naomi ) )
        ken = list( sorted( ken ) )
        naomi_copy = naomi[:]
        ken_copy = ken[:]
        normal_wins = 0
        for x in naomi :
            for y in ken_copy :
                if y > x :
                    naomi_copy.remove( x )
                    ken_copy.remove( y )
                    break 
                #end-if
                #mid-for
            else :
                normal_wins = len( naomi_copy )
                break
            #end-else-for
        #end-for
        naomi = list( reversed( naomi ) )
        ken = list( reversed( ken ) )
        naomi_copy = list( naomi )[:]
        ken_copy = list( ken )[:]
        deceitful_wins = NN        
        for x in naomi :
            for y in ken_copy :
                if x > y :
                    naomi_copy.remove( x )
                    ken_copy.remove( y )
                    break
                #end-if
                #mid-for                    
            else :
                deceitful_wins = NN - len( ken_copy )
                break
            #end-else-for
        #end-for
        print( "Case #{case}: {y} {z}".format(   case=case 
                                               , y=int( deceitful_wins ) 
                                               , z=int( normal_wins ) 
                                             )
        )
    #end-for    
    return 0 # EXIT_SUCCESS
#end-def-main


if __name__ == "__main__" :
    sys.exit( main() )
    #end-if


