from sys import stdin


def read_str(): return stdin.readline().rstrip('\n')
def read_strs(): return stdin.readline().rstrip('\n').split()
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())
def read_floats(): return map(float, stdin.readline().split())


def solve_case():
    smax, digits = read_strs()
    people = []
    for d in digits:
        people.append(int(d))
    
    ans = 0
    already = people[0]
    for i in range(1, len(people)):
        if people[i] > 0 and i > already:
            missing = i - already
            ans += missing
            already += missing
        already += people[i]
    
    return ans

    
def main():
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case()))

        
main()
