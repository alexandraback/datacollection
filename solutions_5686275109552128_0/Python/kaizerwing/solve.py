#!/usr/bin/env python3

import copy

def second_largest(numbers):
    count = 0
    m1 = m2 = -1
    for x in numbers:
        count += 1
        if x > m2:
            if x >= m1:
                m1, m2 = x, m1            
            else:
                m2 = x
    return m2 if count >= 2 else None

def solve(p):
    highest = max(p)
    num_highest = p.count(highest)

    if highest <= 3:
        return highest
    p = list(filter((highest).__ne__, p))
    if (len(p) > 1):
        next_highest = max(p)

    best_base = 2
    best_save = 0
    best_times = highest
    for i in range(2, (highest // 2) + 1):
        times = (highest // i) - 1
        times *= num_highest

        if (len(p) > 1 and next_highest > i + (highest % i)):
            save = highest - next_highest - times
        else:    
            save = highest - (i + (highest % i)) - times
        if save >= best_save and times <= best_times:
            best_save = save
            best_base = i
            best_times = times
    if best_times == highest:
        return highest
    else: 
        
        while True:
            if highest - best_base < best_base:
                p = p + [highest] * num_highest
                break
            else:
                highest = highest - best_base
                p = p + [best_base] * num_highest 
        return best_times + solve(p)

for case in range(int(input())):
    num = int(input())
    p = [int(x) for x in input().strip().split()]
    ans = solve(p)
    print('Case #{}: {}'.format(case + 1, ans))
