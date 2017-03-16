inputfile = file("b-large.in", "rb")
outputfile = file("b-large.out", "wb")
out_yes = "Case #%d: %d"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]

def factorial(n):
    fs=[1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800L, 87178291200L]
    if n<len(fs):
        return fs[n]
    return ((n%1000000007)*(factorial(n-1)%1000000007))%1000000007

def picktwo(stuff):
    for i in xrange(len(stuff)):
        for j in xrange(len(stuff)):
            if i==j:
                continue
            yield stuff[i], stuff[j]

def splitcar(car):
    s = car[0]
    e = car[-1]
    return s, car.rstrip(e).lstrip(s), e
    
def interior(car):
    trimmed = car[1]
    letters_exist = {}
    for c in 'abcdefghijklmnopqrstuvwxyz':
        letters_exist[c] = False
    for c in trimmed:
        letters_exist[c] = True
        
    return [a for a,b in letters_exist.iteritems() if b is True]

def do_case(ncase):
    N, = parse_line()
    cars = inputfile.readline().split()
    cars = [splitcar(car) for car in cars]
    interior_check = {}
    for c in 'abcdefghijklmnopqrstuvwxyz':
        interior_check[c] = False

    for car in cars:
        for c in interior(car):
            if interior_check[c]:
                print >>outputfile, out_yes % (ncase, 0)
                return
            interior_check[c] = True
            
    for s,inter,e in cars:
        if interior_check[s] or interior_check[e]:
            print >>outputfile, out_yes % (ncase, 0)
            return
            
    connectors = {}
    ins = {}
    outs = {}
    for c in 'abcdefghijklmnopqrstuvwxyz':
        connectors[c] = 0
        ins[c] = 0
        outs[c] = 0

    rcars = []
    for car in cars:
        s, inter, e = car
        if inter == '' and s == e:
            connectors[s] += 1
        else:
            rcars.append(car)
            ins[s] += 1
            outs[s] += 1
    
    for c in 'abcdefghijklmnopqrstuvwxyz':
        if ins[c] > 1 or outs[c] > 1:
            print >>outputfile, out_yes % (ncase, 0)
            return
           
    # reduce matches
    factor = 1
    dirty = True
    while dirty:
        dirty = False
        for car1, car2 in picktwo(rcars):
            if car1[2] == car2[0]:
                # Connect the cars
                c = car1[2]
                factor *= factorial(connectors[c])
                factor %= 1000000007
                connectors[c] = 0
                rcars.remove(car1)
                rcars.remove(car2)
                rcars.append((car1[0], '', car2[2]))
                dirty = True
                break
    
    # Check for circles
    for s, i, e in rcars:
        if s == e:
            print >>outputfile, out_yes % (ncase, 0)
            return
    
    for s, i, e in rcars:
        factor *= factorial(connectors[s])
        factor %= 1000000007
        connectors[s] = 0
        factor *= factorial(connectors[e])
        factor %= 1000000007
        connectors[e] = 0
        
    count = len(rcars)
    for c in 'abcdefghijklmnopqrstuvwxyz':
        if connectors[c] != 0:
            count += 1
            factor *= factorial(connectors[c])
            factor %= 1000000007
            connectors[c] = 0
    
    total = factorial(count) * factor
    total %= 1000000007
    print >>outputfile, out_yes % (ncase, total)
    
            
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    do_case(ncase)