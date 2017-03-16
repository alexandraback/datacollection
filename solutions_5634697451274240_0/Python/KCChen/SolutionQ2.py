lines=raw_input()

for question_idx in xrange(1,int(lines)+1):
    line=raw_input()
    change=0

    for s in range(len(line)-1):
        tmp=line[s]
        if line[s+1]!=tmp:
            change += 1

    tail=line[-1]
    count=0

    if tail=='-':
        count +=1
    
    print "Case #{}: {}".format(question_idx,change+count)


