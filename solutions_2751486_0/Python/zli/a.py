vowel = "aeiou"

for case in range(input()):
    print "Case #"+str(case+1)+":",
    name,n=raw_input().split()    
    n = int(n)
    """
    vals = [(c not in vowel)*1 for c in name]

    last = vals[0]
    lastindex = 0
    counts = []
    for i,v in enumerate(vals):
        if v != last:
            counts.append((last,i-lastindex))
            last = v
            lastindex = i
    counts.append((v,i+1-lastindex))

    index = 0
    total = 0
    L = len(name)
    for val,count in counts:
        if val and count >= n:
            #print index, L-(index+count)
            print index, L-(index+n),total
            print index+count-n, L-(index+count)
            total += (1+index) * (1+L-(index+n))
            for i in xrange(index+1, index+count-n):
                total += (1+i) * (1+L-(i+n))
        index += count
    print total
    """

    vals = [(c not in vowel)*1 for c in name]

    lasts = [False for v in vals]
    consec = 0
    for i,v in enumerate(vals):
        if v:
            consec += 1
            if consec >= n:
                lasts[i] = True
        else:
            consec = 0
    #print map(int,lasts)

    totals = [0 for v in vals]
    for i,v in enumerate(vals):
        if lasts[i]:
            totals[i] += i+2-n
        else:
            totals[i] = totals[i-1]
    print sum(totals)
