fin = open('A-small-attempt2.in', 'r')
fout = open('output.txt', 'w')

t = int(fin.readline())

for i in xrange(t):
    a, n = map(int, fin.readline().split())
    motes = map(int, fin.readline().split())
    if a > 1:
        motes.sort()
        result = 101
        created = 0
        for j in xrange(n):
            if a > motes[j]:
                a += motes[j]
            else:
                if n - j + created < result:
                    result = n - j + created
                create = a - 1
                while a <= motes[j]:
                    a += create
                    create *= 2
                    created += 1
                a += motes[j]
        if created < result:
            result = created
        if result == 101:
            result = 0
        fout.write('Case #' + str(i + 1) + ': ' + str(result) + '\n')
    else:
        fout.write('Case #' + str(i + 1) + ': ' + str(len(motes)) + '\n')

fout.close()
