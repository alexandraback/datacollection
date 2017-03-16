import sys

lines = [i[:-1] for i in sys.stdin.readlines()]

t = int(lines[0])

for i in xrange(1, t+1):
    print 'Case #' + str(i) + ':',
    letters = lines[i]
    a = letters[0]
    for c in letters[1:]:
        if ord(c) >= ord(a[0]):
            a = c + a
        else:
            a = a + c        
    print a
    


