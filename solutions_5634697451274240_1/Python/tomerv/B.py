def flip1(x):
    return '+' if x == '-' else '-'

def flip(s, l):
    return ''.join(map(flip1, s[:l])) + s[l:]

def solve(s):
    steps = 0
    while not all(map(lambda x: x == s[0], s)):
        # print(s)
        steps += 1
        prefix = 1
        while s[prefix] == s[0]:
            prefix += 1
        s = flip(s, prefix)
    if s[0] == '-':
        steps += 1
    return steps    

t = int(input())
for i in range(t):
    s = input()
    print('Case #{}: {}'.format(i+1, solve(s)))
