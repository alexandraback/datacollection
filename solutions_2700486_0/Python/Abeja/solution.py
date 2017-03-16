import sys, os, math

class _problem(object):

    @staticmethod
    def _fetch( _name ):
        _source = open( _name , 'r' )

        _t = int( _source.readline() );

        _return = []

        while _t > len( _return ):
            _return.append( _source.readline().strip().split() )

        _source.close()
        return _return

    @staticmethod
    def _each( _data ):

        _q , _x , _y = [ int(_i) for _i in _data ]

        # _q = 7
        # _x = 4
        # _y = 0


        _a = 2
        _b = - 1
        _c = - _q

        _w = int( ( - _b + ( _b**2 - 4 * _a * _c )**(1/2) ) / 2 / _a )

        while _a * _w**2 + _b * _w + _c < 0: _w += 1
        while _a * _w**2 + _b * _w + _c > 0: _w -= 1

        _z = ( abs(_x) + abs(_y) ) >> 1

        _o = _q - ( _a * _w**2 + _b * _w )


        _r = None

        if _z < _w:
            _r = 1
        elif _z > _w:
            _r = 0
        elif _o == 0:
            return 0
        elif _o == 1:
            if _y == 0:
                _r = 1/2
            else:
                _r = 0
        else:
            # print( '-' , _o , '-')
            _total = 0
            _true = 0
            for _i in range(_o+1):
                _j = _o - _i
                if _i > _z*2: continue
                if _j > _z*2: continue
                print( '----' , _i , _j , '-' , _z*2 , _y)

                if _i*_j ==0:
                    _weight = 1
                else:
                    _weight = math.factorial( _o ) / math.factorial( _i ) / math.factorial( _j )


                if _i==_j:
                    _weight = _weight * 2

                if _i>_y:
                    _true += _weight

                _total += _weight



            print( _true , _total )
            if _total > 0:
                _r = _true / _total
            else:
                _r = 0


        print( [ _q , _x , _y ] , _r , [ _w , _z , _o ] )

        # sys.exit();

        return _r

    @staticmethod
    def _solve():
        for _name in [ 'test' , 'small' , 'large' ] if True else [ 'test' ]:
            if os.path.isfile( _name + '.in' ) :
                print( '>> ' + _name )
                _testCases = _problem._fetch( _name + '.in' );
                _return = []
                for _testCase in _testCases:
                    _return.append( 'Case #' + str( len( _return ) + 1 ) + ': ' + str( _problem._each( _testCase ) ) )

                f = open( _name + '.out' , 'w' )
                f.write( "\n".join( _return ) )
                f.close()


_problem._solve();

print( '> done' )