import fileinput

T=-1
case=1

for line in fileinput.input():
    if T<0:
        T=int(line)
    else:
        inputs=line.split(' ')
        N=int(inputs[0])
        S=int(inputs[1])
        p=int(inputs[2])
        Nmore=0
        Nstrange=0
        for gg in xrange(3,N+3):
            score=int(inputs[gg])
            if score - p - 2*max(0,(p - 1)) >=0:
                Nmore+=1
            elif score - p - 2*max(0,(p - 2)) >=0:
                Nstrange+=1
        if Nstrange>S:
            Nstrange=S
        print 'Case #%s: %i'%(case,Nmore+Nstrange)
        case+=1
        if case>T:
            break
