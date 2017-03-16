from itertools import product

def cor(x):
    if x == '?':
        return ['9','8','7','6','5','4','3','2','1','0']
    else:
        return [x]

fp = open("a2s.txt")
fw = open("a2a.txt", 'w')
t = int(fp.readline().strip())
for case in range(t):
    s = fp.readline().strip().split()
    s1, s2 = s
    l1 = [cor(x) for x in s1]
    l2 = [cor(x) for x in s2]
    gap = 100000000
    s1 = ''
    s2 = ''
    for z2 in product(*l2):
        for z1 in product(*l1):
            x2 = int(''.join(z2))
            x1 = int(''.join(z1))
            if abs(x1-x2) <= gap:
                gap = abs(x1-x2)
                s1 = ''.join(z1)
                s2 = ''.join(z2)
    fw.write(('Case #{0}: {1} {2}\n'.format(case+1, s1, s2)))
