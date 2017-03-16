import sys

_inputType = 'small'

_tcs = []
with open(_inputType+'.in','r') as _in:
    _t = int(_in.readline())
    _tcs = []
    while len(_tcs)<_t:
        _tcs.append([int(_x) for _x in _in.readline().strip().split()])
    _in.close()

def _one(_len):

    _result = [ 10**(_len-1) , 2*10**(_len-1) ]

    for _i in range(1,_len):
        for _j in range(_i+1,_len):
            for _k in range(_j+1,_len):
                _result.append( 10**(_len-1) + 10**(_len-1-_i) + 10**(_len-1-_j) + 10**(_len-1-_k) )

    for _i in range(1,_len):
        for _j in range(_i+1,_len):
                _result.append( 10**(_len-1) + 10**(_len-1-_i) + 10**(_len-1-_j) )

    for _i in range(1,_len):
        _result.append( 10**(_len-1) + 10**(_len-1-_i) )

    return _result

def _two(_len):

    _result = [ 10**(_len-1) ]

    for _i in range(1,_len):
        _result.append( 10**(_len-1) + 10**(_len-1-_i) )

    return _result


def _solveTC( _tc , _list):

    _result = 0
    for _x in _list:
        if _x<=_tc[1]:
            if _x>=_tc[0]:
                _result += 1

    print(_tc , _result)

    return _result

################

_list = [1,2,3]

for _i in range(2,53):
    if _i & 1:
        for _j in _one((_i-1)>>1):
            for _k in [0,1]:
                _list.append(int(str(_j)+str(_k)+str(_j)[::-1]))
        for _j in _two((_i-1)>>1):
            _list.append(int(str(_j)+'2'+str(_j)[::-1]))
    else:
        for _j in _one(_i>>1):
            _list.append(int(str(_j)+str(_j)[::-1]))

_list = [_x**2 for _x in _list]


_result = []
for _i , _tc in enumerate( _tcs ):
    _result.append( 'Case #' + str(1+_i) + ': ' + str(_solveTC( _tc , _list )) +  '\n' )

with open(_inputType+'.out','w') as _out:
    _out.writelines(_result)
    _out.close()

print('Done')