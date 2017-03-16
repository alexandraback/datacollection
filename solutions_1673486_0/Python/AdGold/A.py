def nKeepTyping(prc, pri, numChars, charsLeft, charsDone):
	return (1+charsLeft)*prc[charsDone] + \
               (charsLeft + numChars + 2)*pri[numChars - charsLeft]

def restart(numChars): return 2+numChars

def deleteN(prc, pri, n, charsLeft, charsDone, numChars):
	return (2*n + charsLeft + 1) * prc[charsDone-n] +\
	       (2*n + charsLeft + numChars + 2) * pri[charsDone - n]

f = open('A-small-attempt0.in')
out = open('A.out', 'w')

nt = int(f.readline())

for i in xrange(nt):
    charsDone, numChars = map(int, f.readline().split())
    #print numChars, charsDone
    charsLeft = numChars - charsDone
    pr = map(float, f.readline().split())
    #print pr
    prc = [1]
    for p in pr: prc.append(p*prc[-1])
    pri = map(lambda n:1-n, prc)

    m = min(nKeepTyping(prc, pri, numChars, charsLeft, charsDone),
            restart(numChars))

    m2 = min(map(lambda n:deleteN(prc, pri, n, charsLeft, charsDone, numChars),
                 xrange(1, charsDone+1)))

    out.write('Case #%d: %.6f\n' % (i+1, min(m, m2)))

    print nKeepTyping(prc, pri, numChars, charsLeft, charsDone), restart(numChars), map(lambda n:deleteN(prc, pri, n, charsLeft, charsDone, numChars),xrange(1, charsDone+1))

out.close()
