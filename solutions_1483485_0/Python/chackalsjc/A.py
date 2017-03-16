# Google Code Jam 2012 Qualification Round
# A

import string

def translate(g, map):
    trantab = string.maketrans(''.join(map[0]), ''.join(map[1]))
    
    return g.translate(trantab)
    
if __name__ == '__main__':
    map = [
        ['ynficwlbkuomxsevzpdrjgathaq'],
        ['abcdefghijklmnopqrstuvywxyz']
    ]

    T = int(raw_input())
    
    for i in xrange(T):
        G = raw_input()
        print 'Case #%d: %s' % (i+1, translate(G, map))
        
# ynficwlbkuomxsevzpdrjgathaq
# abcdefghijklmnopqrstuvywxyz
