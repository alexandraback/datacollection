# S = K always possible
for t in range(int(input().strip())):
    k, c, s = list(map(int, input().strip().split()))
    print('Case #%d:' % (t + 1), end = '')
    l = k ** c
    half = k // 2
    for i in range(half):
        print(" " + str(i + 1), end = "")
    for i in range(k - half):
        print(" " + str(l - i), end = "")
    print('')
