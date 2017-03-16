#!/usr/local/bin/python

import sys

def match(num, pattern):
    l = len(pattern)

    if num < 0:
        return False

    if len(str(num)) > l:
        return False

    s = str(num).zfill(l)

    for i in range(l):
        if pattern[i] != '?' and pattern[i] != s[i]:
            return False
    return True

def unify(C, J, first_mismatch):
    Cl = []
    Jl = []

    for i in range(first_mismatch):
        if C[i] != '?' and J[i] != '?':
            Cl.append(C[i])
            Jl.append(J[i])
        elif C[i] != '?':
            Cl.append(C[i])
            Jl.append(C[i])
        elif J[i] != '?':
            Cl.append(J[i])
            Jl.append(J[i])
        else:
            Cl.append('0')
            Jl.append('0')

    Cpre = ''.join(Cl)
    Jpre = ''.join(Jl)
    return Cpre, Jpre

def get_best_repl(C, J, first_mismatch):
    Cpre, Jpre = unify(C, J, first_mismatch)
    if first_mismatch == 0 or (C[first_mismatch-1]!='?' and J[first_mismatch-1]!='?'):
        Cr = Cpre + C[first_mismatch:].replace('?', '9')
        Jr = Jpre + J[first_mismatch:].replace('?', '0')
        return Cr, Jr

    Crem = C[first_mismatch:]
    Jrem = J[first_mismatch:]

    C_best = Cpre + Crem.replace('?', '9')
    J_best  = Jpre + Jrem.replace('?', '0')
    diff_best = int(J_best) - int(C_best)

    #print 'DC:', C_best, J_best, diff_best

    C2 = Cpre + Crem.replace('?', '0')
    J2 = Jpre + Jrem.replace('?', '9')

    # Add 1000... to C2, compare
    # Subtract 100... from J2, compare
    to_add = 10**(len(C) - first_mismatch)
    
    C_x = int(C2) + to_add
    #print C_x
    if match(C_x, C):
        diff_x = C_x - int(J2)
        is_best = False
        if diff_x < diff_best:
            is_best = True
        elif (diff_x == diff_best) and C_x<int(C_best):
            is_best = True
        elif (diff_x == diff_best) and C_x==int(C_best) and int(J2)<int(J_best):
            is_best = True

        if is_best:
            C_best = str(C_x).zfill(len(C))
            J_best = J2
            diff_best = diff_x

        #print 'Cx:', C_best, J_best, diff_best

    J_x = int(J2) - to_add
    #print J_x
    if match(J_x, J):
        diff_x = int(C2) - J_x
        is_best = False
        if diff_x < diff_best:
            is_best = True
        elif (diff_x == diff_best) and int(C2)<int(C_best):
            is_best = True
        elif (diff_x == diff_best) and int(C2)==int(C_best) and J_x<int(J_best):
            is_best = True

        if is_best:
            C_best = C2
            J_best = str(J_x).zfill(len(C))
            diff_best = diff_x
        
        #print 'Jx:', C_best, J_best, diff_best

    return C_best, J_best

def solve(t):
    C, J = sys.stdin.readline().rstrip().split()

    first_mismatch = 0
    for i in range(len(C)):
        if C[i] == J[i]:
            first_mismatch += 1
            continue

        elif C[i] == '?' or J[i] == '?':
            first_mismatch += 1
            continue

        else:
            break

    if first_mismatch == len(C):
        Cr, Jr = unify(C, J, first_mismatch)
        print 'Case #{}: {} {}'.format(t, Cr, Jr)
        return

    if C[first_mismatch] > J[first_mismatch]:
        Jr, Cr = get_best_repl(J, C, first_mismatch)
    else:
        Cr, Jr = get_best_repl(C, J, first_mismatch)
    print 'Case #{}: {} {}'.format(t, Cr, Jr)

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
