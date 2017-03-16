import sys

inf = sys.argv[1]

f = open(inf, 'rU')
outf = open(inf + ".out", 'w')

def max_length(iwant, wantme, index, avail, used):
    if len(avail) == 0:
        return [used]

    options = []
    option = iwant[index]
    if option in avail:
        new_avail = set(avail)
        new_avail.remove(option)
        options.extend(max_length(iwant, wantme, option, new_avail, used + [option]))
    for option in wantme[index]:
        if not option in avail:
            continue
        new_avail = set(avail)
        new_avail.remove(option)
        options.extend(max_length(iwant, wantme, option, new_avail, used + [option]))

    return options + [used]


T = int(f.readline())
for t in xrange(T):
    N = int(f.readline())
    prefs = [int(x) for x in f.readline().split()]

    iwant = [None for x in prefs]
    wantme = [[] for x in prefs]

    requirements = []

    for i, pref in enumerate(prefs):
        iwant[i] = (prefs[i]-1)
        wantme[prefs[i] - 1].append(i)
        requirements.append((str(i) + str(prefs[i]-1), str(prefs[i]-1) + str(i)))

    #print requirements


    #print prefs
    #print iwant, wantme
    avail = set()
    for i in xrange(N):
        avail.add(i)

    opts = []
    for start in xrange(N):
        opts.extend(max_length(iwant, wantme, start, avail, []))

    opts.sort(key=len, reverse=True)
    for opt in opts:
        if len(opt) == 0:
            break
        o = "".join((str(x) for x in opt))
        o += o[0]

        met = 0
        for requirement in requirements:
            if requirement[0] in o or requirement[1] in o:
                met += 1

        #print o, met
        if met == len(opt):
            print met
            outf.write("Case #{0}: {1}\n".format(t+1, met))
            break



f.close()
outf.close()
