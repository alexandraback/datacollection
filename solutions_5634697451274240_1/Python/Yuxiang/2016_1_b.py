# Problem B. Revenge of the Pancakes


def done(s):
    return len(s) == 0 or (not '-' in s)
    
    
def flip(s, turns):
    while s[-1] != '-':
        s = s[:-1]
    index = 0
    while s[index] == '+':
        index += 1
    if index > 0:
        for i in range(index):
            s[i] = '-'
        turns += 1
    res = ['-' if x == '+' else '+' for x in s[::-1]]
    turns += 1
    return res, turns


t = int(input())

cases = []
for i in range(t):
    cases.append(list(str(raw_input())))

for index, cake in enumerate(cases):
    turns = 0
    while not done(cake):
        cake, turns = flip(cake, turns)
    print("Case #{}: {}".format(index + 1, turns))
    

