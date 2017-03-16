T = int(input())

for tc in range(1, T+1):
    N = int(input())
    s = set()

    for i in range(2*N-1):
        l = list(map(int, input().split()))
        for x in l:
            if x in s:
                s.remove(x)
            else:
                s.add(x)
    print("Case #{}: {}".format(tc, " ".join(map(str, sorted(map(int, list(s)))))))
