inputfile = file("a-small.in", "rb")
outputfile = file("a-small.out", "wb")
out_s = "Case #%d: %d"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]

def reduce_motes(our_mote, motes):
    touched = True
    while touched:
        touched = False
        for mote in motes:
            if mote < our_mote:
                our_mote += mote
                motes.remove(mote)
                touched = True
                break
    return our_mote, motes
    
def min_steps(our_mote, motes):

    our_mote, motes = reduce_motes(our_mote, motes)
    if len(motes) == 0:
        return 0
        
    if our_mote == 1:
        return len(motes)
        
        
    # Option 1: absorb smallest mote
    next_mote = motes[0]
    opt1 = 1 + min_steps( 2*our_mote-1, motes[:])
    
    # Option 2: kill all the rest
    opt2 = len(motes)

    return min(opt1, opt2)
    
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    our_mote, nmotes = parse_line()
    motes = parse_line()
    our_mote, motes = reduce_motes(our_mote, motes)
    motes.sort()
    
    steps = min_steps(our_mote, motes)
    print >>outputfile, out_s % (ncase, steps)