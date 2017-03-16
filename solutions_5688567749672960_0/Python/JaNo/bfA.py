T = [10000000]*10000000;
T[0] = 0

def r(i):
    return int(str(i)[::-1])

for i in range(1000008):
    T[i+1] = min(T[i+1], T[i]+1)
    T[r(i)] = min(T[r(i)], T[i]+1)

t = int(input())
for i in range(t):
    n = int(input())
    print("Case #%s: %s" % (i+1, T[n]))


