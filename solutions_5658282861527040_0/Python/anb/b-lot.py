from sys import stdin


def read_str(): return stdin.readline().rstrip('\n')
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())
def read_floats(): return map(float, stdin.readline().split())


def solve_case():
    a, b, k = read_ints()
    
    if b < a:
        a, b = b, a
    
    ans = b
    
    for i in range(1, a):
        for j in range(b):
            if i & j < k:
                ans += 1
        
    return ans

    
def main():
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case()))

        
main()
