# from http://stackoverflow.com/questions/312443/how-do-you-split-a-list-into-evenly-sized-chunks-in-python
def chunks(l, n):
    """Yield successive n-sized chunks from l."""
    for i in range(0, len(l), n):
        yield l[i:i+n]

def flatten(v, base):
    total = 0
    power = 1
    for i in v:
        total += power * i
        power *= base
    return total

for case in range(1, input()+1):
    print "Case #%s:" % (case),
    K, C, S = map(int, raw_input().split())
    needed = K / C + (K % C != 0) # Ceiling
    if S < needed:
        print "IMPOSSIBLE"
    else:
        for v in chunks(range(K), C):
            v += [0]*(C - len(v)) # pad with zeros
            print flatten(v, K) + 1,
        print
    #print " ".join(str(i) for i in xrange(1, K+1))
