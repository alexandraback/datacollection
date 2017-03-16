sample = '''ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
yeq

our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
aoz'''.split('\n\n')

letters = set(chr(ord('a') + i) for i in range(26))
unmapped = set(letters)
remaining = set(letters)

d = {c : None for c in letters}
for i in range(len(sample[0])):
    if sample[0][i] in letters:
        d[sample[0][i]] = sample[1][i]
        unmapped.discard(sample[0][i])
        remaining.discard(sample[1][i])
if len(remaining) == 1:
    d[list(unmapped)[0]] = list(remaining)[0]

data = open('A-small-attempt1.in', 'r')
N = int(data.readline().strip())
for case in range(1, N+1):
    message = data.readline().strip('\n')
    output = ''.join(d.get(c, ' ') for c in message)
    print 'Case #{}: {}'.format(case, output)
