
# coding: utf-8

# In[29]:

from collections import Counter
import itertools
import math
import random



# In[34]:

def solve(J, P, S, K):
    combos = list(itertools.product(range(1, 1+J), range(1, 1+P), range(1, 1+S)))
    n = len(combos)
    tries = 10000
    highest, best_answer = 0, []
    for _ in range(tries):
        answer = subsolve(combos, K)
        if len(answer) > highest:
            highest = len(answer)
            best_answer = answer
    return best_answer
        


# In[35]:

def subsolve(combos, K):
    random.shuffle(combos)
    answer = []
    JP, JS, PS = Counter(), Counter(), Counter()
    for combo in combos:
        j, p, s = combo
        if JP[(j,p)] == K:
            continue
        if JS[(j, s)] == K:
            continue
        if PS[(p, s)] == K:
            continue
        # approved
        JP[(j,p)] += 1
        JS[(j,s)] += 1
        PS[(p,s)] += 1
        answer.append(combo)
    return answer


# In[ ]:

if __name__ == "__main__":
    T = int(input())
    for case in range(1, T+1):
        J, P, S, K = map(int, input().split())
        answer = solve(J, P, S, K)
        print("Case #{}: {}".format(case, len(answer)))
        for row in answer:
            print(*row, sep=" ")

