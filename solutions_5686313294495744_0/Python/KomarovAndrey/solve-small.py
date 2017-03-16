
tests = int(input())

for t in range(1, tests + 1):
    n = int(input())
    a, b = [], []
    for i in range(n):
        x, y = [w.strip() for w in input().split()]
        a.append(x)
        b.append(y)
    best = 0
    for mask in range(2 ** n):
        fst, snd = set(), set()
        bits = {bit for bit in range(n) if (1 << bit) & mask}
        for bit in bits:
            fst.add(a[bit])
            snd.add(b[bit])
        ok = all(a[bit] in fst and b[bit] in snd for bit in range(n) if bit not in bits)
        if ok and n - len(bits) > best:
            best = n - len(bits)
    print("Case #{}: {}".format(t, best))
                
                
