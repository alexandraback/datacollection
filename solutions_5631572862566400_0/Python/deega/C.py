#!/bin/python
from collections import deque
def liSub(A):
    count = maxCount = 1
    temp = A[0]
    flag = True
    for i in A[1:]:
        if i > temp:
            count += 1
            temp = i
            flag = False
        elif i == temp:
            count += 1
            flag = True
        elif flag:
            count = 1
            temp = i
        else:
            count = 1
            temp = i
        maxCount = max(maxCount, count)
    return maxCount
T = int(input())
for i in range(T):
    N = int(input())
    d = list(map(int, input().split()))
    play = deque(d) # init playing
    d = deque(d)
    o = max(liSub(list(play)),liSub(list(play)[::-1])) # initial condition
    temp = play.pop()
    play.appendleft(temp)
    while play != d:
        o = max(liSub(list(play)),liSub(list(play)[::-1]),o) # playing
        temp = play.pop()
        play.appendleft(temp)
    print('Case #{}: {}'.format(i+1,o))
