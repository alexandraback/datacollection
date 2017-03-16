from sys import stdin


def read_str(): return stdin.readline().rstrip('\n')
def read_strs(): return stdin.readline().rstrip('\n').split()
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())
def read_floats(): return map(float, stdin.readline().split())

TRANS = [[1,  2,  3,  4], \
         [2, -1,  4, -3], \
         [3, -4, -1,  2], \
         [4,  3, -2, -1]]

SHORTS = set(('ijk', 'jkjk', 'ikik', 'ijij', 'jkkik', 'ikiij', 'jkjij', 'jkkiij'))
         
         
def convert(q):
    if q == '1': return 1
    if q == 'i': return 2
    if q == 'j': return 3
    if q == 'k': return 4
         
         
def mul(a, b):
    if a * b < 0: sign = -1
    else: sign = 1
    a = abs(a)
    b = abs(b)
    return sign * TRANS[a - 1][b - 1]

    
def pow(a, n):
    p = a
    for i in range(n - 1):
        p = mul(p, a)
    return p

def solve_case():
    L, X = read_ints()
    pat = read_str()
    
    pat *= X
        
    expr = list(map(convert, pat))
    
    ithere, jthere, kthere = expr[0] == False, False, False
        
    i = 0
    while i < len(expr):
        if not ithere:
            if expr[i] == 2:
                ithere = True
                i += 1
                continue
        elif not jthere:
            if expr[i] == 3:
                jthere = True
                i += 1
                continue
        if i + 1 < len(expr):
            expr[i + 1] = mul(expr[i], expr[i + 1])
        i += 1
    if expr[-1] == 4:
        kthere = True
            
    ans = ithere and jthere and kthere
    
    return 'YES' if ans else 'NO'

    
def main():
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case()))

        
main()
