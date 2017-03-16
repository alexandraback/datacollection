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
    if a == 1: return 1
    if n == 1: return a
    
    if a != -1:
        if n % 2 == 0:
            a = -1
        n //= 2
    if a == -1:
        if n % 2 == 0: return 1
        else: return -1
    else:
        return 1
    
    
def solve_case():
    L, X = read_ints()
    pat = read_str()
    
    #print('\n' + pat + ' * ' + str(X))
    
    if L * X < 7 and pat * X not in SHORTS:
        return 'NO'
        
    if len(set(list(pat))) == 1:
        return 'NO'
        
    expr = list(map(convert, pat))
    
    while len(expr) != 1:
        new_expr = []
        for i in range(0, len(expr), 2):
            if i + 1 < len(expr):
                new_expr.append(mul(expr[i], expr[i + 1]))
            else:
                new_expr.append(expr[i])
        expr = new_expr
    
    #print(expr[0])
    ans = pow(expr[0], X)
    #print(ans)
    return 'YES' if ans == -1 else 'NO'

    
def main():
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case()))

        
main()
