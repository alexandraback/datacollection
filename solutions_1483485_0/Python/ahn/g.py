'''
Created on 14.4.2012

@author: Antti
'''

g1 = 'ejp mysljylc kd kxveddknmc re jsicpdrysi'
e1 = 'our language is impossible to understand'
g2 = 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'
e2 = 'there are twenty six factorial possibilities'
g3 = 'de kr kd eoya kw aej tysr re ujdr lkgc jv'
e3 = 'so it is okay if you want to just give up'
g4 = 'y qee'
e4 = 'a zoo'

trans = {}

def hmm(g, e):
    global trans
    trans = dict(trans.items() + zip(g,e))



hmm(g1,e1)
hmm(g2,e2)
hmm(g3,e3)
hmm(g4,e4)

#keke = trans.values()
#keke.sort()
#print "".join(keke)

trans['z'] = 'q'

from itertools import imap

def translate(english):
    return "".join(imap(lambda e:trans[e], english))


def solve(filename):
    
    with file(filename) as f:
        cases = int(f.readline().strip())
        
        for i in range(cases):
            words = f.readline().strip()
            print 'Case #%i: %s' % (i+1, translate(words))
            
            
if __name__ == '__main__':
    solve('A-small-attempt1.in')