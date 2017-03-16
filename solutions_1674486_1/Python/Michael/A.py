import collections

def read_line():
    return raw_input().strip()

def read_words():
    return read_line().split()

def read_integer():
    return int( read_line() )

def read_integers():
    return [ int( x ) for x in read_words() ]

T = read_integer()
for t in range( T ):
    print 'Case #%i:' % ( t + 1 ),
    N = read_integer()
    ancestors = collections.defaultdict( set )
    parents = {}
    for n in range( N ):
        parents[ n + 1 ] = set( x for x in read_integers()[ 1 : ] )
    diamond = False
    for node in parents:
##        print 'N', node
        family = parents[ node ].copy()
        while family:
##            print 'F', family
            parent = family.pop()
##            print 'P', parent
            grandparents = parents[ parent ]
            if grandparents:
                if grandparents & family:
                    diamond = True
                    break
                family |= grandparents
            else:
                if parent in ancestors[ node ]:
                    diamond = True
                    break
                else:
                    ancestors[ node ].add( parent )
##                    print '+', parent
##        print 'A', ancestors[ node ]
        if diamond:
            break
    print 'Yes' if diamond else 'No'
