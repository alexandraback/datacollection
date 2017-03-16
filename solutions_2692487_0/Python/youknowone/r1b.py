
def absorb(amote, nmotes, depth=0):
    nmotes = nmotes[:]
    while len(nmotes) > 0 and nmotes[0] < amote:
        amote += nmotes[0]
        del(nmotes[0])
        #print ' ' * depth, '    {} / {}'.format(amote, nmotes)
    return amote, nmotes

def solve(amote, nmotes, maxdepth):
    if len(nmotes) == 0:
        return []
    if 0 > maxdepth:
        raise ValueError
    # first trial
    tamote, tnmotes = absorb(amote * 2 - 1, nmotes, maxdepth)

    try:
        tsolve = solve(tamote, tnmotes, maxdepth=max(maxdepth-1, len(tnmotes)))
    except ValueError:
        dnmotes = nmotes[:-1]
        dsolve = solve(amote, dnmotes, maxdepth=maxdepth-1)
        #print ' ' * maxdepth,'  delf dep{}: {} / {}'.format(maxdepth, amote, dnmotes)
        return [('delreject', (amote, nmotes), (amote, dnmotes))] + dsolve

    if len(tnmotes) < len(nmotes):
        #print ' ' * maxdepth,'  addb dep{}: {} / {}'.format(maxdepth, tamote, tnmotes)
        return [('add', (amote, nmotes), (tamote, tnmotes))] + tsolve

    dnmotes = nmotes[:-1]
    dsolve = solve(amote, dnmotes, maxdepth=maxdepth-1)
    if len(tsolve) < len(dsolve):
        #print ' ' * maxdepth,'  adde dep{}: {} / {}'.format(maxdepth, tamote, tnmotes)
        return [('adde', (amote, nmotes), (tamote, tnmotes))] + tsolve
    else:
        #print ' ' * maxdepth,'  dele dep{}: {} / {}'.format(maxdepth, amote, dnmotes)
        return [('dele', (amote, nmotes), (amote, dnmotes))] + dsolve

if __name__ == '__main__':
    case_count = input()
    for x in xrange(0, case_count):
        amote, ncount = map(int, raw_input().split(' '))
        nmotes = map(int, raw_input().split(' '))
        nmotes.sort()
        #print amote, nmotes
        if amote == 1:
            c = nmotes
        else:
            amote, nmotes = absorb(amote, nmotes)
            c = solve(amote, nmotes, len(nmotes))
        print 'Case #%d:' % (x + 1), len(c)
        for i in c:
            #print i
            pass
        #print '-------'
