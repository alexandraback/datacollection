
fin = open('A-small-attempt0.in', 'r')
fout = open('output.txt', 'w')

t = int(fin.readline())

for i in xrange(t):
    s = fin.readline()
    wordd = ''
    for j in xrange(len(s)):
        if j == 0:
            wordd = s[j]
        elif ord(s[j]) >= ord(wordd[0]):
            wordd = s[j] + wordd
        else:
            wordd = wordd + s[j]
    
    fout.write('Case #' + str(i + 1) + ': ' + wordd)

fout.close()

print 'FINISHED'
