from itertools import product, permutations

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count += 1
        else:
            return count

t = int(input())
for tt in range(t):
    k, l, s = map(int, input().split())
    K = input()
    L = input()

    # how many must I bring
    poss = [''.join(w) for w in product(K, repeat = s)]
    occ = [occurrences(w, L) for w in poss]
    b = max(occ)

    A = sum(occ)
    print("Case #{}: {}".format(tt+1, b - A / len(K) ** s))
