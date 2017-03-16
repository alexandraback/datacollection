import sys, os

class _problem(object):

    @staticmethod
    def _fetch( _name ):
        _source = open( _name , 'r' )

        _t = int( _source.readline() );

        _return = []

        while _t > len( _return ):
            _return.append( [ _source.readline().strip().split() , _source.readline().strip().split() ] )

        _source.close()
        return _return

    @staticmethod
    def _each( _data ):

        _o = int( _data[0][0] )

        _is = sorted( [ int(_i) for _i in _data[1] ] )

        if _o == 1: return len(_is)

        # print( _o , '=>' , _is )

        _min = 10000000000

        for _i in range(len(_is)+1):
            _is3 = _is[0:len(_is)-_i]
            _o3 = int(_o)
            _b = 0
            while len(_is3) > 0:
                _x = _is3[0]
                if _x < _o3:
                    _o3 += _x
                    _is3 = _is3[1:]
                else:
                    _o3 += _o3 - 1
                    _b += 1
            # print( '---------' , _i , _is[0:len(_is)-_i] , _b + _i )
            _min = min( _min , _b + _i)

        return _min
        # print( _o , '=>' , _is , ' | ' , _min )


        # _o1 = int(_o)
        # _is1 = _is[:]
        #
        # _b1 = 0
        # while len(_is1) > 0:
        #     _i = _is1[0]
        #     if _i < _o1:
        #         _o1 += _i
        #         _is1 = _is1[1:]
        #     else:
        #         _o1 += _o1 - 1
        #         _b1 += 1
        #
        # _o2 = int(_o)
        # _is2 = _is[:len(_is)-_b1]
        #
        # _b2 = 0
        # while len(_is2) > 0:
        #     _i = _is2[0]
        #     if _i < _o2:
        #         _o2 += _i
        #         _is2 = _is2[1:]
        #     else:
        #         _o2 += _o2 - 1
        #         _b2 += 1
        #
        #
        # print( _o , '=>' , _is , ' | ' , _b1 , ' ----- ' , _b2 )


        # sys.exit()

        # return 0


        # return _return

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