N = int(input())
for k in range(1, N+1):
    n = int(input())
    if n == 0:
        print("Case #{}: INSOMNIA".format(k))
    else:
        d = [False]*10
        i = 1
        while True:
            cur = n*i
            for dig in str(cur):
                d[int(dig)] = True
            if all(d):
                print("Case #{}: {}".format(k, cur))
                break
            i += 1

