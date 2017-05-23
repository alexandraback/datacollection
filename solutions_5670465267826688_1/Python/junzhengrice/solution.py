'''
Compute a quaternion by brutal force
'''
def multiply(a,b):
    '''
    a * b
    @a: str
    @b: str
    @return : str
    '''
    if a == '1': return b
    if b == '1': return a
    
    if a == '-1':
        if len(b) == 2:
            return b[1]
        else: return '-' + b
    if b == '-1':
        if len(a) == 2:
            return a[1]
        else: return '-' + a

    if a == b: return '-1'
    
    # i * -i
    if a[-1] == b[-1]: return '1'
            
    if a == 'i':
        if b == 'j': return 'k'
        elif b == '-j': return '-k'
        elif b == 'k': return '-j'
        else: return 'j'
    if a == 'j':
        if b == 'i': return '-k'
        elif b == '-i': return 'k'
        elif b == 'k': return 'i'
        else: return '-i'
    if a == 'k':
        if b == 'j': return '-i'
        elif b == '-j': return 'i'
        elif b == 'i': return 'j'
        else: return '-j'
    if a == '-i':
        if b == 'j': return '-k'
        elif b == '-j': return 'k'
        elif b == 'k': return 'j'
        else: return '-j'
    if a == '-j':
        if b == 'i': return 'k'
        elif b == '-i': return '-k'
        elif b == 'k': return '-i'
        else: return 'i'
    if a == '-k':
        if b == 'j': return 'i'
        elif b == '-j': return '-i'
        elif b == 'i': return '-j'
        else: return 'j'
           
    return 'error'   

def divide(a,b):
    '''
    a / b = c
    b * c = a
    @a: str
    @b: str
    @return : str
    '''
    possible = ['1','-1','i','j','k','-i','-j','-k'];
    for c in possible:
        if multiply(b,c) == a:
            return c
    
    return 'error'
    
def compute(Q,L,X):
    DEBUG = False
    
    # compute single string
    single = ['' for x in xrange(0,L)]
    single[0] = Q[0]
    for x in xrange(1,L):
        single[x] = multiply(single[x-1],Q[x])
     
    repeat = 0
    i = 0
    '''
    0 : not yet
    1 : found 'i'
    2 : found 'i','j'
    3 : found 'i','j','k'
    '''
    found = 0
    prev = ['1']
    
    '''
    Maximum search loop
    '''
    period = 4
    if single[-1] == '-1': period = 2
    elif single[-1] == '1': period = 1
    maxLoop = period
    
    while repeat < maxLoop and repeat < X:
        if found == 0:
            while i < L:
                if multiply(prev[0],single[i]) == 'i':
                    found += 1
                    i += 1
                    maxLoop += period
                    break
                i += 1
        elif found == 1:
            while i < L:
                # i * j = k
                if multiply(prev[0],single[i]) == 'k':
                    found += 1
                    i += 1
                    maxLoop += period
                    break
                i += 1  
        elif found == 2:
            while i < L:
                # i * j * k = -1
                if multiply(prev[0],single[i]) == '-1':
                    found += 1
                    i += 1
                    break
                i += 1  
            
        if i == L:
            repeat += 1
            i = 0
            prev[0] = multiply(prev[0],single[-1])
            
        if found == 3: break
    
    if DEBUG: print 'i: ', i, 'found: ', found, 'repeat: ', repeat
    if found != 3: return False
   
    if DEBUG: print 'single[-1]: ', single[-1]
    
    # total must be -1
    total = '1'
 
    if single[-1] == '-1':
        if X % 2 == 1:
            total = '-1'
    elif single[-1] == 'i' or single[-1] == 'j' or single[-1] == 'k' or \
         single[-1] == '-i' or single[-1] == '-j' or single[-1] == '-k':
        if X % 4 == 1:
            total = single[-1]
        elif X % 4 == 2:
            total = '-1'
        elif X % 4 == 3:
            total = multiply('-1',single[-1])
    
    if DEBUG: print 'total: ', total
    return total == '-1'

     
file = open('in.txt','r')
out = open('out.txt','w')
test_cases = file.readlines()

lineId = 1
caseId = 0
while lineId < len(test_cases):
    caseId += 1
    '''
    if caseId != 100: 
        lineId += 2
        continue
    '''
    (L,X) = tuple(map(lambda x:int(x),test_cases[lineId].strip().split(' ')))
    Q = test_cases[lineId+1].strip()
  
    state = compute(Q,L,X)
    answer = 'YES' if state == True else 'NO'
    print >> out, "Case #%d: %s" % (caseId,answer)
    lineId += 2
    
file.close()
out.close()
