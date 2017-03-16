from string import digits
from itertools import product

def possible_scores(template):
    indices = [i for i, c in enumerate(template) if c == '?']
    for p in product(digits, repeat=len(indices)):
        result = list(template)
        for i, c in zip(indices, p):
            result[i] = c
        yield ''.join(result)
     
def solve(first, second):
    dist, result = float('inf'), None
    for s1 in possible_scores(first):
        for s2 in possible_scores(second):
            new_dist = abs(int(s1) - int(s2))
            if new_dist < dist:
                dist, result = new_dist, (s1, s2)
            elif new_dist == dist:
                result = min(result, (s1, s2))
    return result

output = 'Case #{}: {} {}'
t = int(input())
for i in range(t):
    first, second = input().split()
    print(output.format(i + 1, *solve(first, second)))
