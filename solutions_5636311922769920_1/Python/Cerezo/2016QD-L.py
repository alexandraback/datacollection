
def roundup(K,C):
    if not K % C:
        return K/C
    else:
        return 1+int(K/C)

def Next(K,C,S):
    students = roundup(K,C)
    if S < students:
        return 'IMPOSSIBLE'
    else:
        if C > K:
            C = K
        if C == 1:
            return ' '.join(str(i) for i in xrange(1, K+1))
        t0 = sum(i*K**(C-i-1) for i in range(1, C-1))+C
        #print 't0', K, C, t0, students
        tiles = [t0]
        t = t0
        for i in range(students-2):
            t += C*(sum(K**i for i in xrange(C)))
            tiles.append(t)
        if students > 1:
            tiles.append(K**C+1-t0)
        return ' '.join(str(t) for t in tiles)

input = open(r'./D-large.in')
T = int(input.readline())
sol = []
for i in xrange(T):
    K,C,S = (int(i) for i in input.readline().strip().split())
    sol += [Next(K,C,S)]
    if not i%10: print i

tofile = True
if tofile:
    with open(r'./outputD-L.txt', 'w') as output:
        for i in range(len(sol)):
            output.write('Case #%d: %s\n' % (i+1, sol[i]))
else:
    print sol


