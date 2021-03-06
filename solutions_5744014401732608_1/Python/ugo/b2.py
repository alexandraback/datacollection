import math
_f_in = open('b.large.in')
_f_out = open('b.large.out', 'w')

def do_it(_f_in):
    lns = _f_in.readline().split()
    N = long(lns[0])
    VAL = long(lns[1])

    if VAL > (1 << (N-2)):
        _f_out.write('IMPOSSIBLE\n')
        print 'toomuch'
        return

    if VAL == 1:
        _f_out.write('POSSIBLE\n')
        _f_out.write('0' * (N-1) + '1' + '\n')
        for i in range(1, N):
            _f_out.write('0' * N + '\n')
        return


    num_using = int(math.log(VAL-1, 2)) + 1
    ref_val = VAL - (1 << (num_using-1)) - 1

    print 'using', num_using
    _f_out.write('POSSIBLE\n')
    # node 0
    edge = []
    for i in range(0, N - num_using - 1):
        edge.append('0')
    edge.append('1')

    rev_val_s = bin(ref_val)[2:].zfill(num_using-1)
    print VAL, num_using, ref_val, rev_val_s
    for i in range(N - num_using, N - 1):
        # print 'idx', len(rev_val_s)-1 - i + (N - num_using)
        # if rev_val_s[len(rev_val_s)-1 - i + (N - num_using)] == '0':
        if rev_val_s[i - (N - num_using)] == '0':
            edge.append('0')
        else:
            edge.append('1')
    edge.append('1')
    _f_out.write(''.join(edge) + '\n')

    # not using
    for i in range(1, N - num_using - 1):
        _f_out.write(('0'*N) + '\n')

    for i in range(N - num_using - 1, N):
        _f_out.write('0'*(i+1) + '1'*(N-i-1) + '\n')

    #
    # edge_dict = []
    # for i in range(N):
    #     for j in range(i+1, N):
    #         edge_dict.append((i, j))
    #
    # for V in range(1, (1 << (N * (N-1) / 2))):
    #     ass = bin(V)[2:].zfill((N * (N-1) / 2))
    #     # print ass
    #     # print len(ass)
    #     edge = []
    #     for i in range(N):
    #         edge.append([])
    #     for (i, a) in enumerate(ass):
    #         if a == '1':
    #             edge[edge_dict[i][0]].append(edge_dict[i][1])
    #
    #     cnts = [0] * N
    #     cnts[0] = 1
    #     for i in range(0, N-1):
    #         for nb in edge[i]:
    #             cnts[nb] += cnts[i]
    #     if VAL == cnts[-1]:
    #         _f_out.write('POSSIBLE\n')
    #         for i in range(N):
    #             e = []
    #             for j in range(N):
    #                 if j in edge[i]:
    #                     e.append('1')
    #                 else:
    #                     e.append('0')
    #             _f_out.write(''.join(e) + '\n')
    #         print ass
    #         return
    #
    # _f_out.write('IMPOSSIBLE\n')
    # print 'impos??'
    # chars = sorted(chars, key=lambda x: -nums[ord(x)-65])
    # ret.append(chars[0] + chars[1])
    # _f_out.write('{}'.format(' '.join(ret)))


_NUM_CASES = int(_f_in.readline())
for _CASE in range(_NUM_CASES):
    print 'Case #{}: '.format(_CASE+1)
    _f_out.write('Case #{}: '.format(_CASE+1))
    do_it(_f_in)
    # _f_out.write('\n')

_f_out.close()
_f_in.close()
