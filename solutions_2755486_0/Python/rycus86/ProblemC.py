'''
Created on May 12, 2013

@author: rycus
'''

def prepare(attacks, di, ni, wi, ei, si, delta_di, delta_pi, delta_si):
    for num in xrange(ni):
        day = di + num * delta_di
        if day not in attacks: attacks[day] = []
        
        dwi, dei = wi + num * delta_pi, ei + num * delta_pi
        dsi = si + num * delta_si
        
        attacks[day].append( (dwi, dei, dsi) )
    
    pass

__debug = False

def solve(attacks):
    succeeded = 0
    wall = { }
    
    for day in sorted(attacks):
        changes = { }
        for wi, ei, si in attacks[day]:
            scdd = False
            if __debug: print 'Att', day, ':', wi, ei, si
            
            pos = float(wi)
            while pos <= ei:
                if pos not in wall:
                    scdd = True
                    wall[pos] = 0
                    
                    if pos in changes:
                        changes[pos] = max(changes[pos], si)
                    else:
                        changes[pos] = si
                        
                elif wall[pos] < si:
                    scdd = True
                    
                    if pos in changes:
                        changes[pos] = max(changes[pos], si)
                    else:
                        changes[pos] = si
                
                pos += 0.5
        
            if __debug: 
                print '\tSuccess:', scdd, '| wall:', 
                for w in sorted(wall):
                    print w, ':', wall[w], ',', 
                print
                    
            if scdd:
                succeeded += 1
                
        for pos in changes:
            si = changes[pos]
            wall[pos] = max(wall[pos], si)
    
    return succeeded

if __name__ == '__main__':
    with open('../c.in', 'r') as infile:
        with open('../c.out', 'w') as outfile:
            T = int(infile.readline())
            for t in xrange(T):
                N = int(infile.readline())
                
                attacks = { }
                for n in xrange(N):
                    di, ni, wi, ei, si, delta_di, delta_pi, delta_si = map(int, infile.readline().split())
                    prepare(attacks, di, ni, wi, ei, si, delta_di, delta_pi, delta_si)
                
                ret = solve(attacks)
                
                print 'Case #' + str(t+1) + ': ' + str(ret)
                outfile.write('Case #' + str(t+1) + ': ' + str(ret) + '\n')
            