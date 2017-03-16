from collections import Counter

f = open("input.txt", 'r')
T = int(f.readline().strip())
for i in range (0, T):
    N = int(f.readline().strip())
    slist = []
    mlist = []
    for j in range(0, 2*N-1):
        temps = f.readline().split()
        for blah in temps:
            slist.append(blah)
    sset = list(set(slist))
    setcount = []
    for height in sset:
        setcount.append(slist.count(height))
    p = 0
    for blah in setcount:
        if blah % 2 != 0:
            mlist.append(int(sset[p]))
        p +=1
    sortlist = sorted(mlist)
    output = "Case #" + str(i + 1) + ": "
    for stuff in sortlist:
        output += str(stuff) + ' '
    print output
