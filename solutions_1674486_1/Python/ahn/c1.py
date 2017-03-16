'''
Created on 5.5.2012

@author: Antti
'''


class C:
    def __init__(self, id, parents):
        self.id = id
        self.parents = parents
        self._anc = None
        
    def __repr__(self):
        return "%s:%s" % (self.id, self.parents)

    def calc_repa(self, clss):
        self.repa = [clss[i-1] for i in self.parents]
        
    def anc(self):
        if self._anc is not None:
            return self._anc
               
        self._anc = set([self])
        for ps in self.repa:
            self._anc.update(ps.anc())
        
        return self._anc
    
    def diam(self):
        pancs = [p.anc() for p in self.repa]
        for i in range(len(pancs)):
            for j in range(i+1,len(pancs)):
                #print pancs[i], pancs[j]
                if pancs[i].intersection(pancs[j]):
                    return True
        return False
    
        
def calc(cs):
    for c in cs:
        c.calc_repa(cs)
    
    for c in cs:
        if c.diam():
            return "Yes"
    return "No"


def solve(filename):
    
    with file(filename) as f:
        T = int(f.readline().strip())
        
        for i in range(T):
            N = int(f.readline())
            clss = []
            for k in range(N):
                ints = [int(p) for p in f.readline().split()]
                clss.append( C(k+1,ints[1:]) )
            print 'Case #%i: %s' % (i+1, calc(clss))




if __name__ == '__main__':
    solve('A-large.in')