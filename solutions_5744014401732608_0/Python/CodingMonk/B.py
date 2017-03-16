import math
import itertools
from collections import Counter
from collections import deque


T = int(raw_input())

for case_no in xrange(1, T + 1):
    


    B, M = map(int, raw_input().split())

    # ans = ''
    matrix = [[0 for i in xrange(B)] for j in xrange(B)]
    count = 1
    path_length = 1
    matrix[0][B-1] = 1
    if B == 2 and M > 1:
        print 'Case #{}: {}'.format(case_no, 'IMPOSSIBLE')
        continue
    while count < M:
        # print 'count = ',count, M
        path_length += 1
        # print 'path_length = ', path_length
        
        comb = itertools.combinations(range(B)[1:-1], path_length-1)
        for com in comb:
            tup = list(com)
            # print 'tup = ', tup
            # print 'count =', count
            tup.sort()
            matrix[0][tup[0]] = 1
            i = 0
            # print 'loop:'
            for i in xrange(len(tup)-1):
                if matrix[tup[i]][tup[i+1]] == 0:
                    matrix[tup[i]][tup[i+1]] = 1
                else:
                    break
                # print 'i=', i
            # print 'end loop'
            # print 'i=', i
            matrix[tup[i]][B-1] = 1
            count += 1
            if count == M:
                break
        if path_length == B - 1 and count < M:
            print 'Case #{}: {}'.format(case_no, 'IMPOSSIBLE')
            break
        # print matrix
    # print 'ans'
    # print matrix
    if count == M:
        print 'Case #{}: {}'.format(case_no, 'POSSIBLE')
        for row in matrix:
            ans = map(str, row)
            print ''.join(ans)
            # for col in row:
            #     print col,
            # print
    # print 'Case #{}: {}'.format(case_no, ans)