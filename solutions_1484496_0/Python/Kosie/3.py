T = int(input())

for case in range(1, T+1):
    S = list(map(int, input().split()))[1:]
    N = len(S)
    s = sum(S)
    found = False
    print("Case #{}:".format(case))
    values = {}
    for partition in range(1, 1<<N):
        A = set(S[i] for i in range(N) if (partition & (1 << i)) != 0)
        a = sum(A)
        if a in values:
            print(" ".join(map(str, A.difference(values[a]))))
            print(" ".join(map(str, values[a].difference(A))))
            found = True
            break
        values[a] = A
    if not found:
        print("Impossible")
