import sys, os

class _tribe(object):

    def __init__( self , _data ):

        self._d , self._n , self._w , self._e , self._s , self._dd , self._dp , self._ds = _data

        return

class _problem(object):

    @staticmethod
    def _fetch( _name ):
        _source = open( _name , 'r' )

        _t = int( _source.readline() );

        _return = []

        while _t > len( _return ):
            _n = int(_source.readline().strip());
            _x = [];
            while len(_x)<_n:
                _x.append( [ int(_c) for _c in _source.readline().strip().split() ] )
            _return.append( [ _n , _x ] )

        _source.close()
        return _return

    @staticmethod
    def _each( _data ):

        _count = _data[0]


        _tribes = [ _tribe(_x) for _x in _data[1] ]


        _days = []
        for _t in _tribes:
            for _i in range( _t._n ):
                _days.append( _t._d + _i * _t._dd )
        _days = sorted(list(set(_days)))

        print( '-----' , _days )

        _is = [ [0] * 1000 for _i in range(len(_days)+1)]

        _result = 0;

        for _k , _day in enumerate(_days):
            for _j , _t in enumerate(_tribes):
                for _i in range( _t._n ):
                    if _t._d + _i * _t._dd == _day:

                        _int = list(range(_t._w + _i*_t._dp , _t._e + _i*_t._dp))

                        # print(list(range(_t._w + _i*_t._dp , 1 + _t._e + _i*_t._dp)))

                        for _l in _int:
                            if _is[_k][500+_l] < _t._s + _i*_t._ds:
                                _result += 1
                                print('-' ,_j , '-')
                                break

                        for _l in _int:
                            _aaa = max(_t._s + _i*_t._ds , _is[_k+1][500+_l] , _is[_k][500+_l])
                            _is[_k+1][500+_l] = max(_t._s + _i*_t._ds , _is[_k+1][500+_l] , _is[_k][500+_l])


            for _i in range(1000):
                _is[_k+1][_i] = max(_is[_k+1][_i] , _is[_k][_i])


        print( set(_is[len(_days)]) )

        return _result

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