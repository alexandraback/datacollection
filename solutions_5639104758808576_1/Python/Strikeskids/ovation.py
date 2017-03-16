
import sys

def test():
    size, people = input().split(' ')
    size = int(size)+1
    loc = 0
    used = 0
    for i in range(size):
        if loc < i:
            used += i-loc
            loc = i
        am = int(people[i])
        loc += am
    return used

N = int(input())

for i in range(1,N+1):
    print('Case #%d: %s'%(i, test()))