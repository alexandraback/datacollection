def read_line():
    return raw_input().strip()

def read_words():
    return read_line().split()

def read_integer():
    return int( read_line() )

T = read_integer()
for t in range( T ):
    name, n = read_words()
    n = int( n )
    consonants = []
    i = 0
    while i < len( name ):
        while i < len( name ) and name[ i ] in 'aeiou':
            i += 1
        if i < len( name ):
            start = i
            while i < len( name ) and name[ i ] not in 'aeiou':
                i += 1
            if i - start >= n:
                consonants.append( ( start, i - start ) )
    total = 0
    #print name, n
    for index, cstr in enumerate( consonants ):
        #print index, cstr
        for start in range( sum( consonants[ index - 1 ] ) - n + 1 if index else 0, sum( cstr ) - n + 1 ):
            ends = len( name ) - ( max( start + n, cstr[ 0 ] + n ) ) + 1
            total += ends
    print 'Case #%i:' % ( t + 1 ), total
