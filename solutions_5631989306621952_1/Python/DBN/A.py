
fout = open('a.out', 'w')
fin = open('A-large.in', 'r')

t = int(fin.readline())
for x in range(1,t+1):
    s = fin.readline()
    ans = s[0]

    for idx in range(1,len(s)-1):
        if ord(ans[0]) > ord(s[idx]):
            ans = ans + s[idx]
        else:
            ans = s[idx] + ans
    fout.write('Case #{}: {}\n'.format(x, ans))
