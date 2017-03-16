def lista(N, M):
    u = []
    for i in M:
        if u.count(i)==0:
            u.append(i)
    l = []
    for i in u:
        if M.count(i) % 2 == 1:
            l.append(i)
    l.sort() # na vseakii pazharni
    s = ''
    for i in l:
        s+= str(i)+' '
    #print "s:", s
    return s


f = open('input.in', 'r')
T = int(f.readline())
tcs = []

o = open('output.txt', 'w')

for i in range(T):
    M = []
    N = int(f.readline())
    for k in range(2*N-1):
        l = f.readline()
        l = l.split(' ')
        for j in l:
            M.append(int(j))
    M.sort()
    o.write("Case #%s: %s\n" % (i+1, lista(N,M)))

f.close()
o.close()


