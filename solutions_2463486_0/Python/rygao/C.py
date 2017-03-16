def palindrome(x):
    x = str(x)
    return (x == x[::-1])

fas = []

for i in xrange(int(10**1.5)+1):
    if palindrome(i):
        if palindrome(i**2):
            fas.append(i**2)

print len(fas)

f = open('C-small-attempt0.in', 'r')
T = f.readline().strip()
T = int(T)

g = open('output-small0.txt', 'w')

print 'T:', T
for i in xrange(T):
    A, B = f.readline().split()
    A, B = int(A), int(B)

    count = 0
    for fasnum in fas:
        if (A <= fasnum <= B):
            count += 1

    g.write('Case #%d: %d\n' % (i+1, count))


f.close()
g.close()
