# http://code.google.com/codejam/contest/dashboard?c=975485#

import sys

def parse(filename):
    f = open(filename)
    T = int(f.readline())
    for i in range(T):
        line = f.readline().strip()
        terms = line.split()
        A = int(terms[0])
        B = int(terms[1])
        
        line2 = f.readline().strip()
        P = [float(p) for p in line2.split()]
        assert len(P) == A
        
        yield A, B, P
    f.close()

def prob_mat(A, B, P):
    oct2bin3 = {'0': '000', '1': '001', '2': '010', '3': '011', '4': '100', '5': '101', '6': '110', '7': '111'}
    oct2bin2 = {'0': '00', '1': '01', '2': '10', '3': '11'}
    oct2bin1 = {'0': '0', '1': '1'}
    oct2bin = {1: oct2bin1, 2: oct2bin2, 3: oct2bin3}
    oct2bin_a = oct2bin[A]
    probs = {}
    types = []
    
    for i in range(2**A):
        j = 0
        prob = 1.0
        back_n = []

        comb = oct2bin_a[str(i)]
        for c in comb:
            if c == '0':  # right
                prob = prob * P[j]
            else:  # c='1', wrong
                prob = prob * (1 - P[j])
            j += 1  
        probs[comb] = prob
        
    exp_keep_type = 0
    exp_enter = 0
    for i in range(2**A):
        comb = oct2bin_a[str(i)]
        if '1' in comb:
            type_keep = 2*B - A + 2
        else:
            type_keep = B - A + 1
        type_enter = B + 2
        exp_keep_type += probs[comb] * type_keep
        exp_enter += probs[comb] * type_enter
    
    exp_del_n = [0] * A
    for ndel in range(1,A+1):    
        for i in range(2**A):        
            exp_del = 0
            comb = oct2bin_a[str(i)]
            comb_left = comb[:-ndel]
            if '1' not in comb_left:
                exp_del = 1 + B - A + 2*ndel
            else:
                exp_del = B + 1 + 1 + B - A + 2*ndel
            exp = probs[comb] * exp_del
            exp_del_n[ndel-1] += exp            
    min_exp = min(min(exp_del_n), exp_enter, exp_keep_type)
        
    return min_exp

def solve(A, B, P, case):
    min_exp = prob_mat(A, B, P)
    print "Case #%d:" % case, min_exp

def main(filename):
    case = 1
    for A, B, P in parse(filename):
        solve(A, B, P, case)
        case += 1


if __name__ == '__main__':
    main(sys.argv[1])
