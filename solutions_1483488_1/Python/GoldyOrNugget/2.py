import collections
import math

length = None

def shift(n):
    return n % (10**(length-1))*10 + n / (10**(length - 1))

def minShift(n):
    mini = n
    for i in xrange(length-1):
        n = shift(n)
        mini = min(mini, n)
    return mini

buckets = [0] * 2000005
fout = open('out.txt', 'w')
fin = open('in.txt')
lines = fin.readlines()[1:]
for i in xrange(len(lines)):
    line = lines[i].strip()
    if not line: break
    
    a, b = map(int, line.split())
    length = len(str(a))
    total = 0

    for q in xrange(a, b+1):
        buckets[minShift(q)] += 1

    for q in xrange(len(buckets)):
        total += (buckets[q] * (buckets[q]-1)) / 2
        buckets[q] = 0
    fout.write('Case #%d: %d\n' % (i+1, total))
fout.close()
