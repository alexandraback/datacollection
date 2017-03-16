import sys

_inputType = 'large'

_tcs = []
with open(_inputType+'.in','r') as _in:
    _t = int(_in.readline())
    _tcs = []
    while len(_tcs)<_t:
        _head = [int(_x) for _x in _in.readline().strip().split()]
        _body = []
        while len(_body)<_head[0]:
            _body.append( [int(_x) for _x in _in.readline().strip().split()] )
        _tcs.append([_head,_body])
    _in.close()

def _solveTC( _tc):

    _head , _body = _tc

    # print(_body)

    _maxX , _maxY = [0] * _head[1] , [0] * _head[0]

    for _j , _line in enumerate( _body ):
        for _i , _cell in enumerate( _line ):
            _maxX[_i] = max(_maxX[_i],_cell)
            _maxY[_j] = max(_maxY[_j],_cell)

    for _j , _line in enumerate( _body ):
        for _i , _cell in enumerate( _line ):
            if _cell < _maxX[_i]:
                if _cell < _maxY[_j]:
                    return 'NO'

    return 'YES'

_result = []
for _i , _tc in enumerate( _tcs ):
    _result.append( 'Case #' + str(1+_i) + ': ' + str(_solveTC( _tc )) +  '\n' )

with open(_inputType+'.out','w') as _out:
    _out.writelines(_result)
    _out.close()

print('Done')