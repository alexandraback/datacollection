import os
T = int(raw_input())
for i in range(T):
    s = raw_input()
    ans = s.count('+-') + s.count('-+')
    if s[-1] == '-':
        ans += 1
    print "Case #{}: {}".format(i+1, ans)
