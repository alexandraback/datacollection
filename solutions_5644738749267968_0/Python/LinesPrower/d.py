'''
Created on Apr 12, 2014

@author: linesprower
'''
'''
Created on Apr 12, 2014

@author: linesprower
'''
import io, sys
import datetime

def solve(fin):
    def nums():
        return [int(x) for x in fin.readline().split()]
    def fnums():
        return [float(x) for x in fin.readline().split()]
    def num():
        return int(fin.readline())
    
    n = num()
    naomi = fnums()
    ken = fnums()
    naomi.sort()
    ken.sort()
    #print(naomi)
    #print(ken)
    
    war_score = n
    kenp = 0
    for x in naomi:
        while kenp < n and ken[kenp] < x:
            kenp += 1
        if kenp < n:
            war_score -= 1
            kenp += 1        
    
    score = 0
    for x in naomi:
        if x > ken[0]:
            ken = ken[1:]
            score += 1
        else:
            ken = ken[:-1]
    return "%d %d" % (score, war_score)   
        
def main():
    fname = 'd.in'
    if len(sys.argv) > 1:
        fname = sys.argv[1]    
    fin = io.open(fname)
    fout = io.open(fname + '.out', 'w')
    t0 = datetime.datetime.now()    
    t = int(fin.readline())
    
    for i in range(t):
        fout.write('Case #%d: ' % (i + 1))
        fout.write('%s\n' % str(solve(fin)))
    
    print('Time = %s' % str(datetime.datetime.now() - t0))
    fin.close()
    fout.close()
        
if __name__ == '__main__':
    main()