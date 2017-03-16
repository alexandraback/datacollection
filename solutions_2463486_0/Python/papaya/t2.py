import os
import math


f_list = range( 1,10 ) ;#list( )

def reverse_p( p ) :

    str_p=str(p)

    ret_v = 0 ;
    for i  in xrange( len(str_p) -1 , -1 ,  -1 ) :

        s = str_p[i]
        ret_v = ret_v * 10 + int(s)

    return ret_v


def build2(  start, end, weiquan ) :

    for p  in xrange( start ,  end ) :

        tp = reverse_p( p )
        t = p  * weiquan +  tp

        f_list.append(  t )

        for mid in xrange(0 ,10 ) :

            t = (p*10 + mid )  * weiquan +  tp
            f_list.append(  t )


def build(  ) :

    build2( 1,10,10 )

    global  f_list ;
    f_list =  sorted( f_list  )

    #print f_list ;#len(f_list)


    build2( 10,100,100)
    build2( 100,1000,1000 )


    f_list =  sorted( f_list )


def up_bound( v ) :

    low =0;
    high = len( f_list ) - 1;

    ret_pos = high;

    while( low <= high ) :

        mid =(low+high)>> 1

        if( f_list[mid] == v ) :
            return mid

        if( f_list[mid] > v ) :
            ret_pos = mid
            high = mid -1
        else :
            low = mid+ 1

    return ret_pos

def lower_bound( v ) :

    low =0;
    high = len( f_list ) - 1;

    ret_pos = high;

    while( low <= high ) :

        mid =(low+high)>> 1

        if( f_list[mid] == v ) :
            return mid

        if( f_list[mid] > v ) :

            high = mid -1
        else :
            ret_pos = mid
            low = mid+ 1

    return ret_pos

def is_paradim( v ) :

    str_v=str(v)

    len_v=len( str_v) ;


    for i in xrange( 0 ,len_v / 2 , 1 ) :

        if( str_v[i]  !=  str_v[ len_v - 1 -i ]) :
            return False

    return True

def solve( ) :

    start =  up_bound( int( math.sqrt(A ) )  )
    end = lower_bound( int( math.sqrt(B ) ) )


    ret = 0 ;
    for i in xrange( start ,end+1 , 1 ) :

        p = f_list[i]
        v = p **2


        if( v >= A and v <= B ) :

            if( is_paradim( v ) ) :

                ret += 1

    print ret ;


if __name__ == '__main__':


    build()

    T = int( raw_input( ) ) ;

    for t in xrange( 1 , T+1,1) :

        line = raw_input( )
        fields = line.split( " " ) ;

        A = int( fields[0] )
        B = int( fields[1] ) ;

        #print "A: " , A ," ",B

        print "Case #%d: " %( t ) ,
        solve( )









