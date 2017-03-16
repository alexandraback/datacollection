from __future__ import print_function

def split(a):
    a.pop(0)
    a.sort()
    a.reverse()
    if len(a)%2: a.insert(0,0)
    b,c = [],[]
    while a:
        if abs(len(b)-len(c))>=len(a):
            [b, c][len(b)>len(c)].append(a.pop(0))
        else:
            [b, c][sum(b)>sum(c)].append(a.pop(0))
    print(b.pop(0), end='')
    for x in b:
        print(' ', end='')
        print(x, end='')
    print('\n', end='')
    print(c.pop(0), end='')
    for x in c:
        print(' ', end='')
        print(x, end='')
    print('\n', end='')

n = long(raw_input())

for y in xrange(n):
    a = [int(x) for x in raw_input().split()]
    print("Case #",end='')
    print(y+1,end='')
    print(':')
    split(a)
