import os
import sys

sys.stdin = open('test.txt', 'r')
sys.stdout = open('ans.txt', 'w')

T = int(raw_input())

def calc(sm, ss):
    num = 0
    ans = 0
    for i in range(sm+1):
        if not int(ss[i]):
            continue
        if num+ans < i:
            ans += i-(num+ans)
        num += int(ss[i])
    return ans


for t in range(T):
    sm, ss = raw_input().split(' ')
    sm = int(sm)
    ans = calc(sm, ss)
    print 'Case #%d: %d' % (t+1, ans)
