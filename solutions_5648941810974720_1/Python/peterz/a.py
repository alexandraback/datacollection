import string
import math
def f(c, x):
    a[x] = b[c]
    for i in d[x]:
        b[i] -= a[x]    
    #print(b, c, x, a[x])
T = int(input())
d = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
for cc in range(1,T + 1):
    a = [0 for i in range(10)]
    b = {c : 0 for c in string.ascii_uppercase}
    s = input()
    for c in s:
        b[c] += 1
    #print(b)
    f('Z', 0)
    f('W', 2)
    f('U', 4)
    f('F', 5)
    f('X', 6)
    f('S', 7)
    f('G', 8)
    f('I', 9)
    f('N', 1)
    f('T', 3)
    #print(b)
    ans = ''
    for i in range(10):
        ans += str(i) * a[i]
    print('Case #%d:' % cc, ans)

