from functools import lru_cache

def count(size, i):
    #global others
    #print(size, i)
    #print(others)
    while i < len(others) and size > others[i]:
        size += others[i]
        i += 1

    if i == len(others):
        return 0
    
    elif size == 1:
        return len(others)
    else:
        return min(count(size+size-1, i)+1,   len(others)-i)
    
    
T = int(input())

for test in range (T):
    size, num = map(int, input().split())
    others = sorted(list(map(int, input().split())))
    #print(size, num, others)
        
    print("Case #{}: {}".format(test+1, count(size, 0)))


# 2 4 [1, 1, 2, 6]
