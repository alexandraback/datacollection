x = int(input())

for _ in range(x):
    K,C,S = [int(X) for X in input().split()]
    if C*S < K:
        print("Case #"+str(_+1)+": IMPOSSIBLE")
        continue
    G = int(K)
    c = []
    while K > 0:
        c.append(range(K - min(K,C),K))
        K -= C

    n = []
    for itr in c:
        k = C - 1
        a = 0
        for i in itr:
            a += i * G**k
            k -= 1
        n.append(a+1)

    print("Case #"+str(_+1)+": " + " ".join([str(w) for w in n]))