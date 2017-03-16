import math
import sys

fin = open('A-small-attempt0.in', 'r')
fout = open('A.out', 'w')

m = {}

string1 = 'ejp mysljylc kd kxveddknmc re jsicpdrysi \
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd \
de kr kd eoya kw aej tysr re ujdr lkgc jv'

string2 = 'our language is impossible to understand \
there are twenty six factorial possibilities \
so it is okay if you want to just give up'

for i in range(len(string1)):
    m[string1[i]] = string2[i]

m['q'] = 'z'
m['z'] = 'q'
m['\n'] = '\n'

#set1 = set(m.keys())
#set2 = set([m[i] for i in m.keys()])

#print set1
#print set2

#print m

print len(m)

n = int(fin.readline().strip())

for i in range(n):
    inp = fin.readline()
    fout.write('Case #%g: ' %(i + 1))
    for j in inp:
        fout.write(m[j])
    #fout.write('\n')
    
fin.close()
fout.close()
