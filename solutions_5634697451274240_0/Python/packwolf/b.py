import re

with open('B-small-attempt0.in') as f:
    with open('B.out', 'w') as out:
        cases = int(f.readline())
        for i in xrange(1, cases+1):
            line = f.readline()[:-1] + '+'
            line = re.sub('\+{2,}', '+', line)
            line = re.sub('\-{2,}', '-', line)
            print 'Case #{i}: {res}'.format(res=len(line)-1, i=i)
            out.write('Case #{i}: {res}\n'.format(res=len(line)-1, i=i))
