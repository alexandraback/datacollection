from copy import copy

def solve():
    J, P, S, K = [int(x) for x in input().split()]

    high_score = []
    current = []
    occurances = {}
    JACK, PANT, SHIRT = 0, 1, 2

    remains_to_add = J*P*S

    for j in range(1, J+1):
        for p in range(1, P+1):
            occurances[(JACK, PANT, j, p)] = 0
    for j in range(1, J+1):
        for s in range(1, S+1):
            occurances[(JACK, SHIRT, j, s)] = 0

    for p in range(1, P+1):
        for s in range(1, S+1):
            occurances[(PANT, SHIRT, p, s)] = 0

    def dfs(curr_max):
        nonlocal high_score
        nonlocal remains_to_add
        if len(current) + remains_to_add < len(high_score):
            return
        if len(current ) > len(high_score):
            high_score = copy(current)
        nxt = find_next(curr_max)
        if nxt:
           if is_OK_to_add(nxt):
               add_to_lst(nxt)
               #current.append(nxt)
               remains_to_add -= 1
               dfs(nxt)
               remains_to_add += 1
               pop_from_lst(nxt)
               
               #current.pop(-1)
           remains_to_add -= 1
           dfs(nxt)
           remains_to_add += 1

    def find_next(tpl):
        if tpl:
           a, b, c = tpl
           if c < S:
               return a, b, c+1
           elif b < P:
               return a, b+1, 1
           elif a < J:
               return a+1, 1, 1
           return None
        else:
           return (1, 1, 1)

    def is_OK_to_add(nxt):
        # jp:
        if occurances[(JACK, PANT, nxt[JACK], nxt[PANT])] >= K or \
            occurances[(JACK, SHIRT, nxt[JACK], nxt[SHIRT])] >= K or \
            occurances[(PANT, SHIRT, nxt[PANT], nxt[SHIRT])] >= K:
            return False
        return True
    def add_to_lst(nxt):
        occurances[(JACK, PANT, nxt[JACK], nxt[PANT])] += 1
        occurances[(JACK, SHIRT, nxt[JACK], nxt[SHIRT])] += 1
        occurances[(PANT, SHIRT, nxt[PANT], nxt[SHIRT])] += 1
        current.append(nxt)
    def pop_from_lst(nxt):
        occurances[(JACK, PANT, nxt[JACK], nxt[PANT])] -= 1
        occurances[(JACK, SHIRT, nxt[JACK], nxt[SHIRT])] -= 1
        occurances[(PANT, SHIRT, nxt[PANT], nxt[SHIRT])] -= 1
        current.pop(-1)
        
          
    dfs(None)
    res = [str(len(high_score))]
    for itm in high_score:
        res.append(' '.join(str(x) for x in itm))
    return '\n'.join(res)
        
    
    

n_cases = int(input())

for n_case in range(n_cases):
    print("Case #{}: {}".format(n_case+1, solve()))
