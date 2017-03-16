T = int(raw_input())

expos = [1]

def is2s(x):
    while x > expos[-1]: 
        expos.append(expos[-1] * 2)
    if x in expos:
        return True
    else:
        return False

def index(x):
    for e in xrange(len(expos)):
        if x == expos[e]:
            return e

def filt(x, y):
    nx ,ny = x, y

    while not ((ny % nx) == 0):
        a = ny % nx  
        ny = nx
        nx = a
    
    return x / nx, y / nx


for x in xrange(10): 
    expos.append(expos[-1] * 2)


for t in xrange(T):
    A ,B = [int(x) for x in raw_input().split('/')]

    A, B = filt(A, B)
    #print A, B
    
    if not is2s(B): 
        print 'Case #%d: impossible' % (t + 1,)
        continue

    #print expos
    result = None
    if A == 1:
        result = index(B)
    else:
        for e in expos:
            if A < e:
                result = index(B / (e/2))
                break

    print 'Case #%d: %d' % (t + 1, result)
