# Python 3.4

# Codejam, 2014, Round Q, Problem C

import itertools
import sys

def main() :
    TT = int( input() )
    for case in range( 1 , 1+TT ) :
        print( "Case #{case}:".format( case=case ) )
        RR , CC , MM = ( int( x ) for x in input().split() )
        if MM == 0 :
            print(   "c"
                   + "." * ( CC - 1 ) )
            for __ in range( RR - 1 ) :
                print( "." * CC )
            #end-for
            continue
            #mid-if
        elif MM == RR*CC - 1 :
            print(   "c" 
                   + "*" * ( CC - 1 ) 
            )
            for __ in range( RR - 1 ) :
                print( "*" * CC )
            #end-for 
            continue
            #mid-elif
        elif RR == 1 :
            print(   "c" 
                   + "." * ( CC - MM - 1 )
                   + "*" * MM
            )
            continue
            #mid-elif            
        elif CC == 1 :
            print( "c" )
            for __ in range( RR - MM - 1 ) :
                print( "." )
            #end-for
            for __ in range( MM ) :
                print( "*" )
            #end-for
            continue
        #end-elif
        if exhaustive_check( RR , CC , MM ) :
            continue
            #end-if
        print( "Impossible" )
    #end-for    
    return 0 # EXIT_SUCCESS
#end-def-main

def exhaustive_check( RR , CC , MM ) :
    for ii in range( 2 , 1+RR ) :
        for jj in range( 2 , 1+CC ) :
            if MM == RR * CC - ii * jj :
                print(   "c" 
                       + "." * ( jj - 1 ) 
                       + "*" * ( CC - jj )
                )
                for __ in range( ii - 1 ) :
                    print(   "." * jj
                           + "*" * ( CC - jj )
                    )
                #end-for
                for __ in range( RR - ii ) :
                    print( "*" * CC )
                #end-for
                return True
            #end-if
        #end-for
    #end-for

    for ii in range( 1 , RR - 1 ) :
        for jj in range( 1 , CC - 1 ) :
            if MM == ii * jj :
                print(   "c" 
                       + "." * ( CC - 1 ) 
                )
                for __ in range( RR - ii - 1 ) :
                    print( "." * CC )
                #end-for
                for __ in range( ii ) :
                    print(   "." * ( CC - jj )
                           + "*" * jj 
                    )
                #end-for
                return True
            #end-if
        #end-for
    #end-for

    if MM % CC <= CC - 2 and MM // CC <= RR - 3 :
        print(   "c" 
               + "." * ( CC - 1 ) 
        )
        for __ in range( RR - ( MM // CC ) - 2 ) :
            print( "." * CC )
        #end-for
        print(   "." * ( CC - ( MM % CC ) ) 
               + "*" * ( MM % CC )
        )
        for __ in range( MM // CC ) :
            print( "*" * CC )
        #end-for
        return True
    #end-if

    if MM % RR <= RR - 2 and MM // RR <= CC - 3 :
        print(   "c" 
               + "." * ( CC - ( MM // RR ) - 1 ) 
               + "*" * ( MM // RR )
        )
        for __ in range( RR - ( MM % RR ) - 1 ) :
            print(   "." * ( CC - ( MM // RR ) )
                   + "*" * ( MM // RR )
            )
        #end-for
        for __ in range( MM % RR ) :
            print(   "." * ( CC - ( MM // RR ) - 1 )
                   + "*" * ( ( MM // RR ) + 1 )
            )
        #end-for
        return True
    #end-if

    if MM <= ( RR - 2 ) * ( CC - 2 ) :
        print(   "c" 
               + "." * ( CC - 1 ) 
        )
        for __ in range( RR - 2 - ( MM // ( CC - 2 ) ) ) :
            print( "." * CC )
        print(   "." * ( CC - ( MM % ( CC - 2 ) ) )
               + "*" * ( MM % ( CC - 2 ) )
        )        
        for __ in range( MM // ( CC - 2 ) ) :
            print(   "." * 2 
                   + "*" * ( CC - 2 )
            )
        #end-for
        return True
    #end-if

    for ii in range( 1 , RR - 2 ) :
        for jj in range( 1 , CC - 2 ) :
            size = ii * CC + jj * RR - ii * jj 
            if size < MM :
                remaining = MM - size
                xx = CC - 2 - jj
                yy = RR - 2 - ii 
                if remaining <= xx * yy :
                    indent = remaining % yy
                    depth = remaining // yy
                    print(   "c"
                           + "." * ( CC - 1 - jj ) 
                           + "*" * jj
                    )
                    for __ in range( RR - 2 - ii - depth ) :
                        print(   "." * ( CC - jj )
                               + "*" * jj
                        )   
                    #end-for
                    print(   "." * ( CC - jj - indent ) 
                           + "*" * ( indent + jj )
                    )
                    for __ in range( depth ) :
                        print(   "." * 2
                               + "*" * ( CC - 2 )
                        )   
                    #end-for
                    for __ in range( ii ) :
                        print( "*" * CC )
                    #end-for
                    return True
                #end-if
            #end-if
        #end-for
    #end-for

    return False
#end-def

if __name__ == "__main__" :
    sys.exit( main() )
    #end-if


