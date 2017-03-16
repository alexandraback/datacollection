
fout = open('b.out', 'w')
fin = open('B-small-attempt0.in', 'r')

t = int(fin.readline())
for x in range(1,t+1):
    n = int(fin.readline())
    sCounts = [0 for y in range(2501)]
    for idx in range(n*2-1):
        rc = fin.readline().split(' ')
        for s in rc:
            sCounts[int(s)] += 1

    fout.write('Case #{}:'.format(x))
    for idx in range(2501):
        if sCounts[idx] % 2 == 1:
            fout.write(' {}'.format(idx))

    fout.write('\n')
