def read_ints():
    return map(int, raw_input().split())

def read_str():
    return raw_input()


def moteToAdd(a, b):
    m = [a]
    while sum(m) <= b:
        m.append(sum(m)-1)
    return m[1:]

def tryEat(A, Ms):
    if Ms==[]:
        return 0

    while A>Ms[0]:
        A += Ms[0]
        Ms = Ms[1:]
        if Ms==[]:
            return 0

    if A==1:
        return len(Ms)

    toDel = len(Ms)

    toAddMote = moteToAdd(A, Ms[0])
    toAdd = len(toAddMote)
    toAddMote.extend(Ms)
    toAddMote.sort()
    toAdd += tryEat(A, toAddMote)
    return min(toDel, toAdd)
    
def test():
    A, N = read_ints()
    Ms = read_ints()
    Ms.sort()
    return tryEat(A, Ms)
    
    
T=read_ints()[0]
for t in xrange(T):
    print "Case #%d: %s" %(t+1, test())

