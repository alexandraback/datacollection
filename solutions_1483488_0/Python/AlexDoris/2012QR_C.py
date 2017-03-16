def recycledpairs(A, B):
    num = 0
    for n in range(A, B):
        strn = str(n)
        store = set()
        for l in range(1, len(strn)):
            strm = strn[l:] + strn[:l]
            m = int(strm)
            if m <= B and n < m:
                if strn+strm not in store:
                    num += 1
                    store.add(strn+strm)
    return num

T = int(raw_input());
for iCase in range(T):
    line = raw_input();
    items = line.split(' ')
    A, B = int(items[0]), int(items[1])
    num = recycledpairs(A,B)
    print "Case #%d: %d" %(iCase+1, num)

