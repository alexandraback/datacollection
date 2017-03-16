import sys

lines = [line.strip() for line in open(sys.argv[1])]
nrounds = int(lines[0])
lines = lines[1:]

def parsegrp(lines):
    numweights = int(lines[0])
    nweights = sorted([float(x) for x in lines[1].split()])
    kweights = sorted([float(x) for x in lines[2].split()])
    return (numweights, nweights, kweights)

def n_play_war(nweights):
    return nweights[0]


def play_deceit(nweights, kweights):
    while True:
        if n_can_win_all(nweights, kweights):
            return len(nweights)
        else:
            nweights.pop(0)
            kweights.pop()



def n_can_win_all(nweights, kweights):
    for (n,k) in zip(nweights, kweights):
        if k > n:
            return False
    return True


def k_play(nw, kweights):
    for w in kweights:
        if nw < w:
            return w
    return kweights[0]


def play_war(numweights, nweights, kweights):
    ct = 0
    for _ in range(numweights):
        nmove = n_play_war(nweights)
        nweights.remove(nmove)
        kmove = k_play(nmove, kweights)
        kweights.remove(kmove)
        if nmove > kmove:
            ct += 1
    return ct

grps = [parsegrp(lines[3*x:3*x+3]) for x in range(len(lines)/3)]
assert(len(grps) == nrounds)

for ix,g in enumerate(grps):
    (nturns, nweights, kweights) = g
    scr1 = play_deceit(nweights[:], kweights[:])
    scr2 = play_deceit(kweights, nweights)
    print "Case #%d: %d %d" % (ix+1,scr1,nturns - scr2)

