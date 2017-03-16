#!/usr/bin/python

t = int(raw_input())
for case_no in xrange(1, t+1):
    c, j = raw_input().split()
    l = len(c)

    min_diff = 1000
    min_c = None
    min_j = None

    for q in '0123456789':
        for w in '0123456789':
            for e in '0123456789':
                for x in '0123456789':
                    for y in '0123456789':
                        for z in '0123456789':
                            code, jam = '', ''
                            if l >= 1:
                                if c[0] == '?':
                                    code += q
                                else:
                                    code += c[0]
                                if j[0] == '?':
                                    jam += x
                                else:
                                    jam += j[0]
                            if l >= 2:
                                if c[1] == '?':
                                    code += w
                                else:
                                    code += c[1]
                                if j[1] == '?':
                                    jam += y
                                else:
                                    jam += j[1]
                            if l >= 3:
                                if c[2] == '?':
                                    code += e
                                else:
                                    code += c[2]
                                if j[2] == '?':
                                    jam += z
                                else:
                                    jam += j[2]
                            icode = int(code)
                            ijam = int(jam)
                            diff = abs(icode - ijam)
                            if diff < min_diff:
                                min_c, min_j = code, jam
                                min_diff = diff
                            elif diff == min_diff:
                                if icode < int(min_c):
                                    min_c, min_j = code, jam
                                elif icode == int(min_c):
                                    if ijam < int(min_j):
                                        min_c, min_j = code, jam

                            if l < 3 or j[2] != '?': break
                        if l < 2 or j[1] != '?': break
                    if l < 1 or j[0] != '?': break
                if l < 3 or c[2] != '?': break
            if l < 2 or c[1] != '?': break
        if l < 1 or c[0] != '?': break

    print 'Case #%d: %s %s' % (case_no, min_c, min_j)
