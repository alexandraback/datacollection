M = 10000000

say = [0] * M
say[1] = 1
q = [1]
for a in q:
    for b in (a+1, int(str(a)[::-1])):
        if b < M and (not say[b] or say[a] + 1 < say[b]):
            say[b] = say[a] + 1
            q.append(b)

for x in range(1, input() + 1):
    N = input()
    print 'Case #%d:' % x, say[N]
