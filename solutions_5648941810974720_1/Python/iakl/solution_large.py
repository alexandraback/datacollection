input_file = "A-large.in"
output_file = "A-large.out"

in_f = open(input_file)
T = -1
N = -1
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if T == -1:
        T = int(sl)
        continue
    tcs.append(sl)
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    out_f.write("Case #" + str(tcn) + ": " + str(x) + "\n")

def GetWord(d, w, c):
    for ch in w:
        d[ch] -= c

def CheckWord(d, ch, w, dgs, dg):
    if ch in d and d[ch] > 0:
        for i in range(0, d[ch]):
            dgs.append(dg)
        GetWord(d, w, d[ch])

def SolveTestCase(w):
    d = dict()
    for ch in w:
        if not ch in d:
            d[ch] = 0
        d[ch] += 1
    dgs = []
    CheckWord(d, 'Z', 'ZERO', dgs, 0)
    CheckWord(d, 'W', 'TWO', dgs, 2)
    CheckWord(d, 'U', 'FOUR', dgs, 4)
    CheckWord(d, 'X', 'SIX', dgs, 6)
    CheckWord(d, 'G', 'EIGHT', dgs, 8)
    CheckWord(d, 'H', 'THREE', dgs, 3)
    CheckWord(d, 'S', 'SEVEN', dgs, 7)
    CheckWord(d, 'O', 'ONE', dgs, 1)
    CheckWord(d, 'V', 'FIVE', dgs, 5)
    CheckWord(d, 'I', 'NINE', dgs, 9)
    dgs = sorted(dgs)
    r = ""
    for d in dgs:
        r = r + str(d)
    return r

#print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    OutputTestCase(i + 1, r)

out_f.close()

