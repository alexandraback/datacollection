import sys

def solve(s):
    is_first_unhappy = s[0] == '-'
    unhappy_count = len(s.replace('+', ' ').split())
    return 2*unhappy_count - is_first_unhappy

def generate():
    import random
    ans = '500\n'
    for i in range(500):
        for j in range(random.randint(1, 100)):
            if random.random() < 0.5: ans += '+'
            else: ans += '-'
        ans += '\n'
    def check():
        while True: yield True
    return (ans, check)

if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #%d: %d"%(i+1, solve(input())))

