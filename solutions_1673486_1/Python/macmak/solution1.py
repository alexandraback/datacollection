import fileinput

inp=fileinput.input()
line=inp.next()
T=int(line)

case=1
for line in inp:
    inputs=line.split(' ')
    A = int(inputs[0])
    B = int(inputs[1])
    pstring=inp.next()
    prob=[1.0]
    for sp in pstring.split(' '):
        prob.append(float(sp))

    #print A, B, prob
    
    strokes=[]
    
    p=1.0
    for i in xrange(A+1):
        p*=prob[i]
        strokes.append(p*(A-i+B-i+1) + (1.0-p)*(A-i+B-i+1+B+1))
    
    strokes.append(p*(B-A+1) + (1.0-p)*(B-A+1+B+1)) 
    # start again    
    strokes.append(1.0*(1+B+1))
    #print strokes
    strokes.sort()
    print 'Case #%s: %f'%(case,strokes[0])
    case+=1
    if case>T:
        break
