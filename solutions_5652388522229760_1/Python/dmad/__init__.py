x = int(input())

for _ in range(x):
    n = int(input())
    if(n==0):
        print("Case #" + str(_+1)+": INSOMNIA")
        continue
    N = {}
    c = n
    while len(N) < 10:
        S = str(c)
        for s in S:
            N[s] = 0
        c += n
    print("Case #" + str(_+1)+": " + str(c-n))
