fin = file('B-small-attempt1.in', 'r')
fout = file('output.txt', 'w')

t = int(fin.readline())

for i in xrange(t):
    x, y = map(int, fin.readline().split())
    result = ''
    if x > 0:
        result += 'WE'*abs(x)
    else:
        result += 'EW'*abs(x)
    if y > 0:
        result += 'SN'*abs(y)
    else:
        result += 'NS'*abs(y)
    fout.write('Case #' + str(i + 1) + ': ' + str(result) + '\n')
            

fout.close()
