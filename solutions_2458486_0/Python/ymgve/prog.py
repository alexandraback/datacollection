import sys, random

import psyco; psyco.full()

order = None

def recursive(currentkeys, opened, chests, s, remaining, skip_empty):
    global order
    #print s
    
    if order is not None:
        return
        
    if remaining == 0:
        order = s.strip()
    
    foo = range(len(chests))
    random.shuffle(foo)
    
    done = 0
    for i in foo:
        if opened[i]:
            continue
            
        chest = chests[i]
        
        if len(chest[1]) == 0 and skip_empty:
            continue
            
        needed = chest[0]
        if currentkeys[needed] == 0:
            continue
            
        ck = list(currentkeys)
        ck[needed] -= 1
        for k in chest[1]:
            ck[k] += 1
        
        op = list(opened)
        op[i] = True
        
        ss = s + " " + str(i+1)
        
        recursive(ck, op, chests, ss, remaining - 1, True)
        
        done += 1
        
    if done == 0 and skip_empty:
        recursive(currentkeys, opened, chests, s, remaining, False)
        

        

def main():
    global order
    f = open(sys.argv[1], "rb")
    ncases = int(f.readline())
    for caseno in xrange(ncases):
        startkeys, nchests = f.readline().strip().split()
        nchests = int(nchests)
        
        currentkeys = [0] * 400
        keycounts = [0] * 400
        opened = [False] * nchests
        for k in f.readline().strip().split():
            #print k
            currentkeys[int(k)] += 1
            keycounts[int(k)] += 1
            
        chests = []
        for i in xrange(nchests):
            parts = f.readline().strip().split()
            keys = []
            for i in xrange(int(parts[1])):
                keys.append(int(parts[2+i]))
                keycounts[int(parts[2+i])] += 1
                
            chests.append((int(parts[0]), keys))
            keycounts[int(parts[0])] -= 1
            
        #print chests
        order = None
        
        doit = True
        for n in keycounts:
            if n < 0:
                doit = False
                
        if doit:
            recursive(currentkeys, opened, chests, "", nchests, True)
        
        if order is None:
            order = "IMPOSSIBLE"
            
        print "Case #%d: %s" % (caseno+1, order)
        
main()