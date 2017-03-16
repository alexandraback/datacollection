   
def solve(ns):
    total = 0
    added = 0
    for shyness,n in enumerate(ns):
        if shyness > total:
            added += shyness - total
            total = shyness
        total += n
    return added

n_cases = input()

for i in range(1,n_cases+1):
    _,s = raw_input().split(' ')
    ns = map(int,s)
    print "Case #%d: %d" % (i, solve(ns))
 