t = int(input())

for i in range(1, t+1):
    S = input()
    T = ''
    for s in S:
        if T == '':
            T = s
            continue

        if s >= T[0]:
            T = s + T
        else:
            T = T + s

    print("Case #{}: {}".format(i, T))


