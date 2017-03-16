def ken_choice(w_naomi, mine):
    choice = 0
    winners = [n for n in mine if n > w_naomi]
    if not winners:
        choice = min(mine)
    else:
        choice = min(winners)
    mine.remove(choice)
    return choice

def naomi_lie(n, his):
    min = his[0]
    max = his[-1]
    if n > min:
        return max + 0.00000001
    else:
        return max - 0.00000001

def read_line():
    line = raw_input()
    return [float(n) for n in line.split()]

def war():
    size = input()
    naomi = read_line()
    ken = read_line()
    c1 = 0
    k1 = [n for n in ken]
    for n in naomi:
        k = ken_choice(n, k1)
        if n > k:
            c1 += 1

    c2 = 0

    ken.sort()
    for n in sorted(naomi):
        l = naomi_lie(n, ken)
        k = ken_choice(l, ken)
        if n > k:
            c2 +=1

    print "%d %d" % (c2, c1)

total = input()
for t in xrange(1, total+1):
    print "Case #%d:" % t,
    war()
