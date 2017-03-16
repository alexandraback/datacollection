import sys
sys.stdin = open('a.in', 'r')
sys.stdout = open('a.out', 'w')

def solve():
    n = int(input())
    x = [int(c) for c in input().split()]
    ans = 10000
    for T in range(1, 1001):
        tmp = 0
        for i in range(n):
            tmp += (x[i]+T-1)//T-1
        tmp += T
        if tmp<ans:
            ans = tmp
    return ans

for T in range(int(input())):
    print('Case #%d: %s' % (T+1, solve()))