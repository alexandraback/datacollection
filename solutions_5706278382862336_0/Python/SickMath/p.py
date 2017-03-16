import sys
import StringIO
import math
import fractions

def memfile(test_data):
    out = StringIO.StringIO()
    out.write(test_data)
    out.seek(0)
    return out

test_data = '''5
1/2
3/4
1/4
2/23
123/31488
'''

infile = open(sys.argv[1]) if len(sys.argv) > 1 else memfile(test_data)

def reduce(P, Q):
    gcd = fractions.gcd(P, Q)
    return P/gcd, Q/gcd

def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)

def check_impossible(P, Q):
    P, Q = reduce(P, Q)
    if not is_power2(Q):
        return 'impossible'
    if math.log(Q, 2) > 40:
        return 'impossible'
    return P, Q

def ge_one(P, Q):
    return P >= Q 

def find_anc(P, Q, n):
    if ge_one(P, Q/2):
        return n+1
    else:
        return find_anc(P, Q/2, n+1)

def solve(P, Q):
    chk = check_impossible(P, Q)
    if chk == 'impossible':
        return 'impossible'
    else:
        P, Q = chk
        return find_anc(P, Q, 0)

def write_solution(infile):
    infile.readline()
    out = []
    for cnt, line in enumerate(infile):
        [P, Q] = map(int, line.strip().split('/'))
        res = solve(P, Q)
        out.append('Case #%s: %s' % (cnt+1, res))
    f = open('out.txt', 'w')
    f.write('\n'.join(out) + '\n')
    f.close()

write_solution(infile)
