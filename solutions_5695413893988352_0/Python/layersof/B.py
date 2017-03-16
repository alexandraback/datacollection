DEBUG=0

def main():
    N = input()
    for i in range(N):
        C, J = raw_input().split()
        print 'Case #%d: %s' % (i+1, ' '.join(map(str, solve(C, J))))


def nexts(c):
    if c == '9':
        return ('8', '9', '0')
    elif c == '0':
        return ('9', '0', '1')
    elif c == '1':
        return ('0', '1', '2', '9')
    elif c == '8':
        return ('0', '7', '8', '9')
    else:
        tmp = ord(c)
        return ('0',) + tuple(map(chr, (tmp-1, tmp, tmp+1))) + ('9',)

def solve(C, J):
    cand_c = []
    cand_j = []
    for c, j in zip(C, J):
        if c == '?':
            if j == '?':
                cand_c.append(('9', '0', '1'))
                cand_j.append(('9', '0', '1'))
            else:
                cand_c.append(nexts(j))
                cand_j.append(())
        else:
            if j == '?':
                cand_c.append(())
                cand_j.append(nexts(c))
            else:
                cand_c.append(())
                cand_j.append(())

    return rec(C, J, cand_c, cand_j)

def better(new, current):
    if current is None:
        # if DEBUG: print 'BETTER:', new, current
        return new
    else:
        # if DEBUG: print 'BETTER:', new, current
        C, J = new
        if abs(int(C) - int(J)) < abs(int(current[0]) - int(current[1])):
            return new
        elif (abs(int(C) - int(J)) == abs(int(current[0]) - int(current[1]))
              and int(C) + int(J) < sum(map(int, current))):
            return new
        else:
            return current

def rec(C, J, cand_c, cand_j, current=None):
    if DEBUG: print 'rec%s' % ((C, J, cand_c, cand_j, current),)
    if ('?' not in C) and ('?' not in J):
        result = better((C, J), current)
        if DEBUG: print ' ->', result
        return result
    for i, cs in enumerate(cand_c):
        if cs and C[i] == '?':
            for k, c in enumerate(cs):
                if DEBUG: print '<CS %s[%d] for %s:' % (cs, k, (C, J))
                result = rec(C[:i]+c+C[i+1:], J,
                             cand_c[:i]+[()]+cand_c[i+1:],
                             cand_j,
                             current)
                current = better(result, current)
                if DEBUG: print current, '>'


    for i, js in enumerate(cand_j):
        if js and J[i] == '?':
            for k, j in enumerate(js):
                if DEBUG: print '<JS %s[%d] for %s:' % (js, k, (C, J))
                result = rec(C, J[:i]+j+J[i+1:],
                             cand_c,
                             cand_j[:i]+[()]+cand_j[i+1:],
                             current)
                current = better(result, current)
                if DEBUG: print current, '>'

    if DEBUG: print '->', current
    return current
    

# def rec(C, J, cand_c, cand_j, current=None):
#     if ('?' not in C) and ('?' not in J):
#         return better((C, J), current)

#     if DEBUG: print 'rec:', C, J, cand_c, cand_j, current

#     for i, cs in enumerate(cand_c):
#         if cs and C[i] == '?':
#             for c in cs:
#                 result = rec(C[:i]+cs[0]+C[i+1:], J,
#                              cand_c[:i]+[cs[1:]]+cand_c[i+1:],
#                              cand_j,
#                              current)
#                 print 'CS:', cs[0], cs[1:], result, current,
#                 current = better(result, current)
#                 print '>', current

#     for i, js in enumerate(cand_j):
#         if js and J[i] == '?':
#             for j in js:
#                 result = rec(C, J[:i]+js[0]+J[i+1:],
#                              cand_c,
#                              cand_j[:i]+[js[1:]]+cand_j[i+1:],
#                              current)
#                 print 'JS:', js[0], js[1:], result, current,
#                 current = better(result, current)
#                 print '>', current

#     print '->', current
#     return current




























if __name__ == '__main__':
    main()
