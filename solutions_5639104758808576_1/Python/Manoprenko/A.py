fin = open('a.in', 'r')
fout = open('a.txt', 'w')

t = int(fin.readline())
for ii in range(t):
    s = list(map(int, list(fin.readline().split()[1])))
    cnt = res = 0
    i = 0
    while i < len(s):
        if cnt >= i:
            cnt += s[i]
            i += 1
        else:
            res += 1
            cnt += 1
    print('Case #', ii + 1, ': ', res, sep='', file=fout)

fin.close()
fout.close()