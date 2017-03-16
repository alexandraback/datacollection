
fin = open('B-large.in', 'r')
fout = open('output.txt', 'w')

t = int(fin.readline())

for i in xrange(t):
    h = [0]*2501
    n = int(fin.readline())
    for k in xrange(2*n - 1):
        heights = map(int, fin.readline().split())
        for j in heights:
            h[j] += 1
    answer = []
    for j in xrange(1, 2501):
        if h[j]%2 == 1:
            answer += [j]
    fout.write('Case #' + str(i + 1) + ': ' + ' '.join(str(x) for x in answer) + '\n')

fout.close()

print 'FINISHED'
