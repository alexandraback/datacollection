t = int(input())
for i in range(t):
    s = input()
    c = 0
    for j in range(len(s) - 1):
        if s[j] != s[j + 1]:
            c += 1
    if s[-1] == '-':
        c += 1
    print('Case #', i + 1, ': ', c, sep='')