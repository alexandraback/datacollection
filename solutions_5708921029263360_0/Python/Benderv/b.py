from itertools import combinations, permutations, product
from collections import defaultdict

def fashion(J, P, S, K):
    if J == P == S == 1:
        print(1)
        print(J, P, S)
        return
    clothes = [J, P, S]
    clothes.remove(max(clothes))
    comb = clothes[0]*clothes[1]
    days = min(J*P*S, comb*K)
    print(days)
    
    JP = defaultdict(int)
    JS = defaultdict(int)
    PS = defaultdict(int)
    outfit = defaultdict(int)
    wear = product(range(1, J+1), range(1, P+1), range(1, S+1))
    possible = False
    while max(max(JP.values(), default=0), max(JS.values(), default=0), max(PS.values(), default=0)) <= K:
        try:
            d = next(wear)
        except:
            if not possible:
                return
            possible = False
            wear = product(range(1, J+1), range(1, P+1), range(1, S+1))
            d = next(wear)
        if outfit[d] >= 1:
            continue
        if JP[(d[0], d[1])] >= K:
            continue
        if JS[(d[0], d[2])] >= K:
            continue
        if PS[(d[1], d[2])] >= K:
            continue
        possible = True
        JP[(d[0], d[1])] += 1
        JS[(d[0], d[2])] += 1
        PS[(d[1], d[2])] += 1
        outfit[d] += 1
        print(' '.join([str(i) for i in d]))
    


t = int(input())

for i in range(t):
  line = [int(i) for i in input().strip().split(' ')]
  print("Case #"+str(i+1)+": ", end="")
  fashion(*line)

