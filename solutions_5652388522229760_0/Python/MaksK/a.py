t = int(input())
for ii in range(1, t+1):
    n = int(input())
    m = n
    s = set()
    for i in range(10000):
        s.update(str(m))
        if len(s) == 10:
            break
        m += n
    else:
        print("Case #{}: INSOMNIA".format(ii))
        continue
    print("Case #{}: {}".format(ii, m))
