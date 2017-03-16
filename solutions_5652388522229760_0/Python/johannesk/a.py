def solve(n):
    if n==0: return "INSOMNIA"
    d=set(str(n))
    m=n
    while len(d)<10:
        m += n
        d.update(str(m))
    return m

for t in range(int(input())):
    print("Case #{}: {}".format(t+1, solve(int(input()))))
