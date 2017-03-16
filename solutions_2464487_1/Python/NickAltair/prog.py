input = open("input.txt", 'r')
output = open("output.txt", 'w')
import math

def f(x):
    cur = x*(2*r + 1) + 2*x*(x-1)
    return cur <= t

test = int(input.readline())
for test_ind in range(test):
    a = list(input.readline().split())
    r = int(a[0])
    t = int(a[1])
    l,m = 0,t
    x = int((l+r)/2)
    ans = -1
    while l <= m:
        x = int((l+m)/2)
        if f(x) and (not f(x+1)):
            ans = x
        if f(x): l = x+1
        else: m = x-1
    output.write('Case #'+str(test_ind+1)+': '+str(ans)+'\n')

input.close()
output.close()
