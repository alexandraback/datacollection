import sys
import re

vowels = 'aeiou'
consonants = 'bcdfghjklmnpqrstvwxyz'

f = open(len(sys.argv) > 1 and sys.argv[1] or 'test.in', 'r')

T = int(f.readline())
for t in range(T):
    name, n = f.readline().strip().split()
    n = int(n)
    regex = '[%s]{%d,}' % (consonants, n)
    
    count = 0
    for i in range(len(name) + 1):
        for j in range(i + n, len(name) + 1):
            if re.search(regex, name[i:j]):
                count += 1
    
    print('Case #%d: %d' % (t + 1, count))

f.close()