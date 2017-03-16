input()
n, j = map(int, input().split())

i = int('1'+'0'*(n-2)+'1', 2)

solns = []

while True:
    s = bin(i)[2:]
    factors = []
    for b in range(2, 11):
        x = int(s, b)
        F = 0
        for f in range(2, min(10000, x)):
            if x%f==0:
                F = f
                break
        if F==0:
            factors = None
            break
        else:
            factors.append(F)
    if factors:
        solns.append((s, factors))
    i+=2
    if i >= 2**n:
        break
    if len(solns)>=j:
        break

print("Case #1:")
for soln in solns:
    print(soln[0], end=' ')
    for fact in soln[1]:
        print(fact, end=' ')
    print()
