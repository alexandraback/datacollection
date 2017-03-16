from functools import *
from collections import Counter

inf = open('A-large.in')
ouf = open('output.txt', 'w')
input = lambda: inf.readline().strip()
print = partial(print, file = ouf)


n2s = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

def process(stat, ans, digit, count):
    ans[digit] += count
    for c in n2s[digit]:
        stat[c] -= count

def solve():
    s = input().lower()
    stat = Counter(s)
    ans = [0] * 10
    if stat['z']:
        process(stat, ans, 0, stat['z'])
    if stat['w']:
        process(stat, ans, 2, stat['w'])
    if stat['u']:
        process(stat, ans, 4, stat['u'])
    if stat['x']:
        process(stat, ans, 6, stat['x'])
    if stat['g']:
        process(stat, ans, 8, stat['g'])
    if stat['r']:
        process(stat, ans, 3, stat['r'])
    if stat['f']:
        process(stat, ans, 5, stat['f'])
    if stat['s']:
        process(stat, ans, 7, stat['s'])
    if stat['i']:
        process(stat, ans, 9, stat['i'])
    if stat['o']:
        process(stat, ans, 1, stat['o'])
    if any(stat.values()):
        print('NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO')
    else:
        for i in range(10):
            print(str(i) * ans[i], end='')
        print()
    
    
tests = int(input())
for z in range(tests):
    print("Case #{}: ".format(z + 1), end = '')
    solve()

ouf.close()