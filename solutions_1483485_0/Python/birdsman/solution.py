import operator
import itertools
import functools
import math

gl = '''
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
'''

nl = '''
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
'''

def learn():
    glLi = [x for x in list(gl)]
    nlLi = [x for x in list(nl)]
    gnMap = dict(zip(glLi, nlLi))
    gnMap['q'] = 'z'
    gnMap['z'] = 'q'
    return gnMap
    
learn()
     
fn = open('1.in')
ofn = open('1.out', 'w')
TC = int(fn.readline())
gnMap = learn()
for tc in range(TC):
    L = fn.readline().strip()
    res = ''.join([gnMap[x] for x in L])
    #print res
    #print tc       
    print >>ofn, 'Case #{}: {}'.format(tc +1, res)
        
        
