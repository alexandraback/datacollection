
# coding: utf-8

# In[10]:

def binary_ints(x):
    return map(int, bin(x)[2:])


# In[3]:

list(binary_ints(7))


# In[18]:

2**3


# In[22]:

def solve(B, M):
    if M > 2**(B-2):
        return False, []
    
    if M == 2**(B-2):
        M -= 1
        bonus = 1
    else:
        bonus = 0
    
    matrix = [[0] * B for _ in range(B)]
    
    # connect 1 to (2, ..., B), and n to (n+1, ..., B)
    for building in range(B-1):
        for other_building in range(building+1, B-1):
            matrix[building][other_building] = 1
    for building, connect in enumerate(reversed(list(binary_ints(M))), 1):
        matrix[building][B-1] = connect
    if bonus:
        matrix[0][B-1] = 1
    
    return True, matrix


# In[23]:

solve(5, 8)


# In[ ]:

if __name__ == "__main__":
    T = int(input())
    for case in range(1, T+1):
        B, M = map(int, input().split())
        possible, matrix = solve(B, M)
        answer = "POSSIBLE" if possible else "IMPOSSIBLE"
        print("Case #{}: {}".format(case, answer))
        if possible:
            for row in matrix:
                print(*row, sep="")

