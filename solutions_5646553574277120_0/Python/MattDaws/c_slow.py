import itertools

def gen_all(C, D, V):
    """C = max numbr of coins of one type
    D = list of demons
    V = maximum to make"""
    poss = set()
    # This is O( (C+1)**D )
    for choice in itertools.product(range(C+1), repeat = len(D)):
        s = 0
        for c, d in zip(choice, D):
            s += c * d
        if 0 < s and s <= V:
            poss.add(s)
    return list(poss)

def solve(C, D, V):
    count = 0
    while True:
        can_make = gen_all(C, D, V)
        can_make.sort()
        done = True
        for i, x in enumerate(can_make):
            if x != i+1:
                D.append(i+1)
                count += 1
                done = False
                break
        if done: return count

num_cases = int(input())
for case in range(1, num_cases+1):
    C, num_D, V = [int(x) for x in input().split()]
    D = [int(x) for x in input().split()]
    print("Case #{}: {}".format(case, solve(C,D,V)))
