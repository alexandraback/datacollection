import sys

import psyco; psyco.full()

def main():
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline().strip())
    
    for caseno in xrange(ncases):
        numlevels = int(f.readline().strip())
        
        stars = 0
        steps = 0
        levels = []
        state = []
        for i in xrange(numlevels):
            parts = f.readline().strip().split()
            
            #REVERSED ORDER
            levels.append((int(parts[1]), int(parts[0]), i))
            state.append(0)
            
        levels.sort()
        
        
        while True:
            if stars == numlevels * 2:
                break
                
            taken = False
            for two, one, id in levels:
                #print "dsddsd", two, one, id, state[id]
                if state[id] != 2 and stars >= two:
                    #print "taking level for two", id, one, two
                    stars += 2 - state[id]
                    steps += 1
                    taken = True
                    state[id] = 2
                else:
                    if state[id] == 2:
                        continue
                    else:
                        break
                    
            for two, one, id in levels[::-1]:
                if state[id] == 0 and stars >= one:
                    #print "taking level for one", id, one, two
                    stars += 1
                    steps += 1
                    taken = True
                    state[id] = 1
                    break
                    
            if not taken:
                break
                
        
        if stars == numlevels * 2: 
            s = str(steps)
        else:
            s = "Too Bad"
                
        print "Case #%d: %s" % (caseno+1, s)
main()