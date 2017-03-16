fin = open('mote.in')
cases = int(fin.readline())
fout = open('mote.out','w')

def pp(case, out):
    ss= "Case #%d: %s\n" % (case+1, out)
    print ss,
    fout.write(ss)

for case in xrange(cases):
    size, moteCount = map(int, fin.readline().split(" "))
    motes = map(int, fin.readline().split(" "))
    #print size
    motes.sort()
    #print motes
    #simple case is to remove all of the motes
    minn = moteCount
    if size-1 == 0:
        pp(case,minn)
        continue
    cnt = 0
    #otherwise
    #loop
    while True:
        #while we can absorb any motes, do so
        while motes and motes[0]<size:
            size+=motes[0]
            motes = motes[1:]
        
        if not motes:
            minn = min(minn, cnt)
            break
        # we cannot absorb the next one by generating one
        if size+size-1 <= motes[0]:
            #calc min for removing the rest
            minn = min(minn, cnt + len(motes))
        motes.append(size-1)
        cnt+=1
        motes.sort()
        
    pp(case,minn)
    #we have to determine whether, if absorbing the next one is better than removing it
    #at this porint maybe we should work backwards or branch because there is at most 100 motes
    #lets say the last one is 1000, and second to last is 100, and third to last is 5...
    #wait, if we decide to remove and its not the last one, we effectively decided to remove all of the rest
    
fout.close()
    
    