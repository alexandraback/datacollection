def solve( x , B ) :
    s = str( x ) ;
    n = len( s ) ;

    st = set() ;
    for i in xrange(n):
        if s[i] != '0':
            news = s[i::] + s[0:i] ;
            if int(news) > x and int(news) <= B :
                st.add( int(news) ) ;


    return len(st) ;

cases = int( raw_input() ) ;

for cs in xrange(cases) :
    A , B = map( int , raw_input().split() ) ;
    ret = reduce( (lambda x , y : x + y) , [solve( xx , B )  for xx in xrange( A , B+1 ) ] ) ;
    print "Case #%d: %d" %( cs+1 , ret ) ;

