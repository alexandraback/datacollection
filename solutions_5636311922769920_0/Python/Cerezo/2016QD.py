
def Next(K,C,S):
    if S == K:
        return ' '.join(str(i) for i in range(1, K+1))

input = open(r'./D-small-attempt0(1).in')
T = int(input.readline())
sol = []
for i in xrange(T):
    K,C,S = (int(i) for i in input.readline().strip().split())
    sol += [Next(K,C,S)]
    if not i%10: print i

tofile = True
if tofile:
    with open(r'./outputD.txt', 'w') as output:
        for i in range(len(sol)):
            output.write('Case #%d: %s\n' % (i+1, sol[i]))
else:
    print sol


