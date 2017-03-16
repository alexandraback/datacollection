
# coding: utf-8

# In[1]:

import itertools


# In[11]:

def solve(scores):
    template = scores.replace("?", "{}")
    def options():
        for combo in itertools.product("0123456789", repeat=scores.count("?")):
            score = template.format(*combo)
            c, j = map(int, score.split())
            yield (abs(c-j), c, j, score)
    best = min(options())
    diff, c, j, score = best
    return score
    


# In[ ]:

cases = int(input())

for case in range(1, 1+cases):
    answer = solve(input())
    print("Case #{}: {}".format(case, answer))

