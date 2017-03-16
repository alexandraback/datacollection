import math
import sys
import collections

def print_result (case_num,result):
    print('Case #{}: {}'.format(case_num,result))

def flip (state,n):
    return ''.join(['+'if a=='-' else '-' for a in state[n-1::-1]]) + state[n:]

def bfs (first):
    seen = {first : 0}
    target = ''.join(['+' for _ in first])
    q = collections.deque()
    current = first
    while current != target:
        step = seen[current]
        for n in range(1,len(first)+1):
            next_state = flip(current,n)
            if next_state not in seen:
                seen[next_state] = step + 1
                q.append(next_state)
        current = q.popleft()
    return seen[target]

def mex (state):
    old = '+'
    count = 0
    for c in state:
        if old == '+' and c == '-':
            count += 1
        old = c
    if state[0] == '+':
        count = 2 * count
    else:
        count = 2 * count - 1
    return count

T = int(input())
for case_num in range(1,T+1):
    state = input()
    #r1 = bfs(state)
    r2 = mex(state)
    #if r1 != r2:
    #    print(case_num,r1,r2,file=sys.stderr)
    print_result(case_num,r2)
