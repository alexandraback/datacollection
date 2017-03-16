fin = open('pogo.in')
cases = int(fin.readline())
fout = open('pogo.out','w')

def pp(case, out):
    ss= "Case #%d: %s\n" % (case+1, out)
    print ss,
    fout.write(ss)


for case in xrange(cases):
    x,y = map(int,fin.readline().split(' '))
    sol=''
    distx = abs(x)
    disty = abs(y)
    if x<0:#start going to the right
        sol+='EW'*distx
    else:
        sol+='WE'*distx
    
    if y<0:#start going up
        sol+='NS'*disty
    else:
        sol+='SN'*disty
    pp(case,sol)
        
    
        