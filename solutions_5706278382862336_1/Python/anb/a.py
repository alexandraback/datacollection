from sys import stdin


def read_str(): return stdin.readline().rstrip('\n')
def read_strs(): return stdin.readline().rstrip('\n').split()
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())
def read_floats(): return map(float, stdin.readline().split())


def gcd(a, b):
    while b != 0:
        c = a % b
        a, b = b, c
    return a


def solve_case():
    p, q = map(int, read_str().split('/'))
    
    d = gcd(p, q)
    p /= d
    q /= d
    
    if (q & (q - 1)) != 0:
        return 'impossible'
    
    gen = 0
    while q != 1:
        gen += 1
        q /= 2
        if p > q:
            break
            
    return gen

    
def main():
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case()))

        
main()
