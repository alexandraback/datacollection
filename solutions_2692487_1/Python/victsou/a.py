sz = 0

def add_mote(sz, motes):
    motes.insert(0, sz - 1)
    old = motes[:]

    for i, n in enumerate(old):
        if n < sz:
            sz += n
            motes.remove(n)

    return sz

def check_remaining(sz, motes):
    old = motes[:]

    for n in old:
        if n < sz:
            sz += n
            motes.remove(n)

    return sz, len(motes)
    

t = int(raw_input())

for i in range(t):
    sz, n = map(int, raw_input().split())
    motes = sorted(map(int, raw_input().split()))

    firstsz, firstmotes = sz, motes[:]

    sz, best = check_remaining(sz, motes)
    add = 0

    while True:
        sz, ignore = check_remaining(sz, motes)
        if check_remaining(sz, motes)[1] == 0:
            break

        oldlen = len(motes)
        sz = add_mote(sz, motes)

        if sz == 1:
            break
        else:
            add += 1

        sz, ignore = check_remaining(sz, motes)
        best = min(best, add + check_remaining(sz, motes)[1])

    print "Case #" + str(i+1) + ": " + str(best)
