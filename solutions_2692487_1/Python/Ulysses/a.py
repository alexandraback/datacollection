filename = 'A-large'

f = open(filename + '.in')

outfile = open(filename + '.out', 'w')


def best(motes, size):
    while size > motes[0]:
        size += motes[0]
        del motes[0]
        
        if len(motes) == 0:
            break
    
    if len(motes) == 0: return 0
    
    size += size-1
    if size == 1:
        return len(motes)
    
    add =  1 + best(motes[:], size)
    #print len(motes), add
    return min(len(motes), add)
    


for case in xrange(int(f.readline())):
    mysize, number_motes = map(int, f.readline().split())
    all_motes = map(int, f.readline().split())
    all_motes.sort()
    #print all_motes, mysize, 
    answer= best(all_motes, mysize)
    print answer
    outfile.write("Case #%d: %d\n" % (case+1, answer))
    





outfile.close()
f.close()
