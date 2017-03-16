import fileinput

inp=fileinput.input()
line=inp.next()
T=int(line)

case=1
for line in inp:
    N = int(line)
    levels=[]
    stars=[]
    for i in xrange(N):
        line=inp.next()
        inputs=line.split(' ')
        levels.append((int(inputs[0]),int(inputs[1])))
        stars.append(0)
        
    S=0
    tries=0
    for l in xrange(N):
        for ll in xrange(N):
            if levels[ll][1]<=S and stars[ll]!=2:
                tries+=1
                S+=2-stars[ll]
                stars[ll]=2

    for m in xrange(N):
        for l in xrange(N):
            for ll in xrange(N):
                if levels[ll][0]<=S and stars[ll]==0:
                    tries+=1
                    S+=1
                    stars[ll]=1
                    break
            for x in xrange(N):
                for ll in xrange(N):
                    if levels[ll][1]<=S and stars[ll]!=2:
                        tries+=1
                        S+=2-stars[ll]
                        stars[ll]=2

    toobad=False
    for i in xrange(N):
        if stars[i]!=2:
            toobad=True
    if toobad:
        print 'Case #%s: %s'%(case,'Too Bad')
    else: 
        print 'Case #%s: %i'%(case,tries)
    case+=1
    if case>T:
        break
