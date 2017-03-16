def main( ) :
  fin = open( 'smallA.in', 'r' );
  fout = open( 'smallA.out', 'w' );
  
  line = fin.readline( );
  N = map( int, line.split( ) );
  
  for cs in range( 1, N[ 0 ]+1 ) :
    line = fin.readline( );
    pr = map( int, line.split( ) );
    R = pr[ 0 ];
    T = pr[ 1 ];
    
    best = 0;
    lo = 1;
    hi = 10000000000000000;
    
    while lo < hi :
      if lo == hi-1 :
        for i in range( lo, hi+1 ) :
          tmp = 2*R*i - i + 2*i*i;
          if tmp <= T and i > best :
            best = i;
        break;
      else :
        mid = int( ( lo+hi )/2 );
        if 2*R*mid - mid + 2*mid*mid <= T :
          best = mid;
          lo = mid;
        else :
          hi = mid;
    
    fout.write( "Case #{0}: {1}\n".format( cs, best ) );
    
main( );