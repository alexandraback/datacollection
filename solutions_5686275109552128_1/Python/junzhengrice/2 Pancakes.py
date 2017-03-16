file = open('in.txt','r')
out = open('out.txt','w')
test_cases = file.readlines()

def compute(diners):
    DEBUG = False
    
    diners.sort(reverse = True)
    if DEBUG: print diners
    
    minTime = diners[0]
    slot = 2
    newTime = minTime
    
    while slot < diners[0]:
        used = 0
        for d in diners:
            if d <= slot: continue
            used += d // slot
            if d % slot == 0:
                used -= 1
            
        newTime = used + slot
        if DEBUG: print 'slot: ', slot
        if DEBUG: print 'newTime: ', newTime
   
        slot += 1
        
        if newTime < minTime:
            minTime = newTime
    
    return minTime

lineId = 1
caseId = 0
while lineId < len(test_cases):
    caseId += 1
    
    diners = map(lambda x : int(x),test_cases[lineId+1].strip().split(' '))
    
    answer = compute(diners)
    
    #print "Case #%d: %d" % (caseId,answer)
    print >> out, "Case #%d: %d" % (caseId,answer)
    lineId += 2

file.close()
out.close()