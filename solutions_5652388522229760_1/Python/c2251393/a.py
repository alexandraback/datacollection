#! /usr/bin/env python3

tc = int( input() )
for cs in range( 1 , tc+1 ):
    n = int( input() )
    if n == 0:
        print( "Case #%d: INSOMNIA" % cs )
        continue
    digs = set()
    tmp = n
    while True:
        # print( "now %d %d" % ( tmp , len( digs ) ) )
        list( map( digs.add , "%d" % tmp ) )
        if len( digs ) >= 10:
            print( "Case #%d: %d" % ( cs , tmp ) )
            break
        tmp += n

