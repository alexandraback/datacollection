from sys import stdin

def read_str(): return stdin.readline().rstrip('\n')
def read_strs(): return stdin.readline().rstrip('\n').split()
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())
def read_floats(): return map(float, stdin.readline().split())


def solve_case():
    R, C, W = read_ints()
    
    prev_hits = C // W * (R - 1)
    
    hits = C // W - 1
    c = C - W * hits
    
    hits += min(c, W + 1)
    
    return hits + prev_hits

    
def main():
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case()))

        
main()
