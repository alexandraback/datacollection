#!/usr/bin/python
# vi: set fileencoding=utf-8 :

'''
Google code jam 2016 round 1 B
'''

def answer(n, C, J):
    if n == 2:
        C = '0' + C
        J = '0' + J
    elif n == 1:
        C = '00' + C
        J = '00' + J
    gap_min = 1000
    c_ans = 0
    j_ans = 0
    for c0 in range(10):
        if C[0] != '?' and c0 != int(C[0]):
            continue
        for c1 in range(10):
            if C[1] != '?' and c1 != int(C[1]):
                continue
            for c2 in range(10):
                if C[2] != '?' and c2 != int(C[2]):
                    continue
                for j0 in range(10):
                    if J[0] != '?' and j0 != int(J[0]):
                        continue
                    for j1 in range(10):
                        if J[1] != '?' and j1 != int(J[1]):
                            continue
                        for j2 in range(10):
                            if J[2] != '?' and j2 != int(J[2]):
                                continue
                            c = [c0, c1, c2]
                            j = [j0, j1, j2]
                            gap = abs((100*c0 + 10*c1 + c2) - (100*j0 + 10*j1 + j2))
                            if gap < gap_min:
                                gap_min = gap
                                c_ans = c
                                j_ans = j

    if n == 2:
        c_ans = c_ans[1:]
        j_ans = j_ans[1:]
    elif n == 1:
        c_ans = c_ans[2:]
        j_ans = j_ans[2:]
    return ''.join(map(str, c_ans)) + ' ' + ''.join(map(str, j_ans))


T = int(raw_input())
for case_number in range(1, T + 1):
    C, J = raw_input().rstrip().split()
    print 'Case #%d: %s' % (case_number, answer(len(C), C, J))
