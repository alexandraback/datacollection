from sys import stdin
from math import ceil, floor

def read_str(): return stdin.readline().rstrip('\n')
def read_strs(): return stdin.readline().rstrip('\n').split()
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())
def read_floats(): return map(float, stdin.readline().split())

PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]

def check(pancakes):
    pancakes.sort()
    return pancakes[-1]

    
def split(n, parts):
    a = n // parts
    b = n - (parts - 1) * a
    return [b] + ([a] * (parts - 1))
     

def solve_case():
    read_int() #D
    pancakes = list(read_ints())
    
    stack = [(pancakes, 0)]
    starting_ans = ans = max(pancakes)
    
    while len(stack) > 0:
        pancakes, splits = stack.pop()
        biggest = check(pancakes)
        ans = min(ans, biggest + splits)
        if biggest > 3:
            count = 0
            while len(pancakes) > 0 and pancakes[-1] == biggest:
                pancakes.pop()
                count += 1
            for p in PRIMES:
                if p < biggest:
                    parts = split(biggest, p)
                    new_splits = (len(parts) - 1) * count
                    if splits + new_splits < starting_ans:
                        stack.append((pancakes + (parts * count), splits + new_splits))
    
    return ans

    
def main():
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case()))

        
main()
