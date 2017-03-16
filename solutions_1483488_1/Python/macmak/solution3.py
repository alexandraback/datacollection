import fileinput

T=-1
case=1

def turn(i,r):
    s=i.__str__()
    res1=s[r:]
    res2=s[:r]
    return int(res1+res2)

for line in fileinput.input():
    if T<0:
        T=int(line)
    else:
        recycled=set()
        inputs=line.split(' ')
        A=int(inputs[0])
        B=int(inputs[1])
        for i in xrange(A,B+1):
            for r in xrange(1,len(i.__str__())):
                ii=turn(i,r)
                if A<=ii<=B and i!=ii:
                    recycled.add((i,ii))
        
        print 'Case #%s: %i'%(case,recycled.__len__()/2)
        case+=1
        if case>T:
            break
