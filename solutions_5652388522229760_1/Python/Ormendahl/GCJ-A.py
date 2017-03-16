t = int(input())
for i in range(t):
    n = int(input())
    if n == 0:
        print('Case #', i + 1, ': INSOMNIA', sep='')
        continue
    s = 0
    c = 0
    b = [0] * 10
    while c < 10:
        s += n
        s1 = str(s)
        for j in range(len(s1)):
            if b[int(s1[j])] == 0:
                b[int(s1[j])] = 1
                c += 1
    print('Case #', i + 1, ': ', s, sep='')