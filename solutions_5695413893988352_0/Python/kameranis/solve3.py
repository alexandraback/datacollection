#!/usr/bin/env python

def solve(f, s, N, M, j):
    # print f, s, N, M, j
    if j >= len(N):
        return (abs(f-s), f, s, N, M)
    if N[j] != '?' and M[j] != '?':
        return solve(f*10+int(N[j]), s*10+int(M[j]), N[:], M[:], j+1)
    elif N[j] != '?' and M[j] == '?':
        if f == s:
            a = int(N[j])
            f = f*10 + a
            s = s*10
            lst = []
            M[j] = str((a+1) % 10)
            lst.append(solve(f, s + int(M[j]), N[:], M[:], j+1))
            M[j] = str(a)
            lst.append(solve(f, s + int(M[j]), N[:], M[:], j+1))
            M[j] = str((a-1) % 10)
            lst.append(solve(f, s + int(M[j]), N[:], M[:], j+1))

            return min(lst)
        elif f > s:
            M[j] = '9'
            f = f*10 + int(N[j])
            s = s*10 + int(M[j])
            return solve(f, s, N, M, j+1)
        else:
            M[j] = '0'
            f = f*10 + int(N[j])
            s = s*10 + int(M[j])
            return solve(f, s, N, M, j+1)
    elif N[j] == '?' and M[j] != '?':
        if f == s:
            a = int(M[j])
            s = s*10 + a
            f = f*10
            lst = []
            N[j] = str((a+1) % 10)
            lst.append(solve(f + int(N[j]), s, N[:], M[:], j+1))
            N[j] = str(a)
            lst.append(solve(f + int(N[j]), s, N[:], M[:], j+1))
            N[j] = str((a-1) % 10)
            lst.append(solve(f + int(N[j]), s, N[:], M[:], j+1))

            return min(lst)
        elif f > s:
            N[j] = '0'
            f = f*10 + int(N[j])
            s = s*10 + int(M[j])
            return solve(f, s, N, M, j+1)
        else:
            N[j] = '9'
            f = f*10 + int(N[j])
            s = s*10 + int(M[j])
            return solve(f, s, N, M, j+1)

    elif N[j] == '?' and M[j] == '?':
        lst = []
        for n, m in [('0', '0'), ('0', '1'), ('1', '0'), ('0', '9'), ('9', '0')]:
            N[j] = n
            M[j] = m
            lst.append(solve(f*10 + int(N[j]), s*10 + int(M[j]), N[:], M[:], j+1))
        # print lst
        return min(lst)

for i in xrange(int(raw_input())):
    N, M = raw_input().split()
    N = list(N)
    M = list(M)
    f = 0
    s = 0
    _, _, _, N, M = solve(f, s, N, M, 0)

#    for j in range(len(N)):
#        if N[j] != '?' and M[j] == '?':
#            if f == s:
#                M[j] = N[j]
#            elif f > s:
#                M[j] = '9'
#            else:
#                M[j] = '0'
#
#        elif N[j] == '?' and M[j] != '?':
#            if f == s:
#                N[j] = M[j]
#            elif f > s:
#                N[j] = '0'
#            else:
#                N[j] = '9'
#
#        elif N[j] == '?' and M[j] == '?':
#            if f == s:
#                N[j] = '0'
#                M[j] = '0'
#            elif f > s:
#                N[j] = '0'
#                M[j] = '9'
#            else:
#                N[j] = '9'
#                M[j] = '0'
#        f = f*10 + int(N[j])
#        s = s*10 + int(M[j])
    N = ''.join(N)
    M = ''.join(M)
    print "Case #{}: {} {}".format(i+1, N, M)

