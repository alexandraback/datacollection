import sys, copy

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for case in xrange(1, cases+1):
    honest = 0
    deceitful = 0
    stdin.pop(0)
    strnaomi = stdin.pop(0).strip('\n').split(' ')
    naomi = []
    for n in strnaomi:
        floatn = float(n)
        naomi.append(floatn)
    strkevin = stdin.pop(0).strip('\n').split(' ')
    kevin = []
    for k in strkevin:
        floatk = float(k)
        kevin.append(floatk)
    deceitfulkevin = copy.copy(kevin)
    for n in naomi:
        winningblocks = [k for k in kevin if k > n]
        if len(winningblocks):
            kevin.remove(min(winningblocks))
        else:
            kevin.remove(min(kevin))
            honest += 1
    kevin = deceitfulkevin
    while len(naomi):
        maxk = max(kevin)
        losingblocks = [n for n in naomi if n < maxk]
        if maxk > max(naomi) and len(losingblocks):
            kevin.remove(maxk)
            naomi.remove(min(losingblocks))
        else:
            k = min(kevin)
            kevin.remove(k)
            minwin = [n for n in naomi if n > k]
            if len(minwin):
                naomi.remove(min(minwin))
                deceitful += 1
            else:
                naomi.remove(min(naomi))
    print "Case #"+str(case)+": "+str(deceitful)+" "+str(honest)
