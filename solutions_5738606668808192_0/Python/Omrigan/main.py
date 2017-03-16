task = 'C'
type = 1
attempt = 1

outp = open('%s.out' % (task,), 'w')


def is_prime(N):
    for i in range(2, int(N ** 0.5) + 1):
        if N % i == 0:
            return i
    return -1


N = 16
J = 50
used = set()
ansewrs = dict()
import random

while len(used) < J:
    a = ''.join([random.choice(['0', '1']) for i in range(N - 2)])
    a = '1' + a + '1'
    divs = []
    for j in range(2, 11):
        val = int(a, j)
        div = is_prime(val)
        if div != -1:
            divs.append(div)
        else:
            break
    if len(divs) == 9:
        used.add(a)
        print(len(used))
        ansewrs[a] = divs
outp.write("Case #1:\n")
for v in ansewrs:
    outp.write(v + " ")
    for d in ansewrs[v]:
        outp.write('%s ' % (d,))
    outp.write('\n')
