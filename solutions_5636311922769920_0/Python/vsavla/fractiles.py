t = int(input())

for i in range(1, t+1):
    kcs = input().split()
    k, c, s = int(kcs[0]), int(kcs[1]), int(kcs[2])
    print("Case #%d: " % i, end='')
    for res in range(1, s):
        print(res, end=' ')
    print(s)