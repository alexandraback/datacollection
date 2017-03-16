T = int(raw_input().strip())

N, J = map(int, raw_input().strip().split(' '))

found = 0
ctr = 0
fstr = '1{0:0'+str(N-2)+'b}1'

# Fill with actual prime numbers later
plist = range(2,1000)
print 'Case #1:'
while found < J:
    curstr = fstr.format(ctr)
    ctr += 1
    facts = curstr
    for b in xrange(2,11):
        curval = int(curstr,b)
        sat = False
        for p in plist:
            if p*p > curval:
                break
            if curval % p == 0:
                sat = True
                facts += ' ' + str(p)
                break
        if sat == False:
            break
    if sat == True:
        found += 1
        print facts
        