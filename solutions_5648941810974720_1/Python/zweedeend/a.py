
# coding: utf-8

# In[2]:

from collections import Counter


# In[7]:

def solve(S):
    answer = ""
    letters = Counter(S)
    while "X" in letters:
        answer += "6"
        letters -= Counter("SIX")
    while "Z" in letters:
        answer += "0"
        letters -= Counter("ZERO")
    while "G" in letters:
        answer += "8"
        letters -= Counter("EIGHT")
    while "W" in letters:
        answer += "2"
        letters -= Counter("TWO")
    while "H" in letters:
        answer += "3"
        letters -= Counter("THREE")
    while "U" in letters:
        answer += "4"
        letters -= Counter("FOUR")
    while "F" in letters:
        answer += "5"
        letters -= Counter("FIVE")
    while "S" in letters:
        answer += "7"
        letters -= Counter("SEVEEN")
    while "O" in letters:
        answer += "1"
        letters -= Counter("ONE")
    while "N" in letters:
        answer += "9"
        letters -= Counter("NINE")
    assert not letters
    return "".join(sorted(answer))


# In[ ]:

cases = int(input())

for case in range(1, 1+cases):
    answer = solve(input())
    print("Case #{}: {}".format(case, answer))

