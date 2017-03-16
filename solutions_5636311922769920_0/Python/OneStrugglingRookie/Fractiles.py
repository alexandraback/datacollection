import os


if os.path.exists('Fractiles.out'):
    print 'removing file'
    os.remove('Fractiles.out')

Small = True

if Small:
    f = open('D-small-attempt0.in','r')
else:
    f = open('D-large.in','r')

output = open('Fractiles.out','a')
Data = f.read()
Data = Data.split('\n')
T = int(Data[0])
Data = Data[1:]

for t in xrange(T):
    line = 'Case #'+ str(t+1) + ': '
    data = Data[t]
    data = data.split(' ')
    K = int(data[0])
    C = int(data[1])
    S = int(data[2])
    if Small:
        Pos = ''
        Delta = K**(C-1)
        pos = 1
        for k in xrange(K):
            Pos += str(pos)
            Pos += ' '
            pos += Delta
    line += Pos
    line += '\n'
    output.write(line)

output.close()