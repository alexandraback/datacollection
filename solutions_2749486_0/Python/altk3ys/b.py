def solve(x,y):
    xx,yy = abs(x),abs(y)
    return ('EW'*xx if x < 0 else 'WE'*xx) +('NS'*yy if y < 0 else 'SN'*yy)

rd=raw_input
for t in range(1,1+int(rd())):
    print 'Case #%d: %s'%(t,solve(*map(int,rd().split())))
