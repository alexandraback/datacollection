import os
T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    if N == 0:
        ans = "INSOMNIA"
    else:
        d = set()
        ans = 0;
        while len(d) < 10:
            ans += N
            d |= set(str(ans))
    print "Case #{}: {}".format(i+1, ans)
