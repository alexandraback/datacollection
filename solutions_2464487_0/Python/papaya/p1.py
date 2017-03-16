#! /usr/bin/env python
#coding=utf-8

import random ;
import math ;
import sys ;
    

if  __name__ == '__main__' :

    T = int( raw_input() ) 
    for t in xrange( 1 , T + 1 , 1 ) : 
        
        
        print "Case #%d: " %( t ) , 
        
        line = raw_input( ) 
        fields = line.split( " " ) 
        for i in xrange( len( fields ) ) : 
            
            fields [ i ] = fields[ i ].strip( ) 
            
        
        r = float( fields[0] ) 
        t = float( fields[ 1 ] )
        
        
        v = math.sqrt( 8.0 * t + (2*r-1)**2 ) - ( 2 * r - 1 ) 
        
        
        v /= 4
        
        
        v = int( v ) 
        
        m = v 
        
        while True : 
            
            f = 2 * m * ( m + 1 ) + ( 2 * r - 3 ) * m 
            if( f <= t ) : 
                break 
            
            m-=1
            
    
        print m 
        
            
            
        
        
