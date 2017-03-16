
def r(n):
    if n == 0: return "INSOMNIA"
    s = set()
    x = 0
    while len(s) < 10:
        x += n
        s.update(str(x))
    return x

t = int(input())
for i in range(t):
    print("Case #" + str(i+1) + ":", r(int(input())))
