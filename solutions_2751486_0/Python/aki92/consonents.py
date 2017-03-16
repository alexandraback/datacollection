t = input()
for i in xrange(t):
    inp = raw_input().split()
    name = inp[0]
    n = int(inp[1])
    nval = 0
    namelen = len(name)
    for j in xrange(namelen):
        for k in xrange(j+n,namelen+1):
            word = name[j:k]
            #print word
            vowel = ['a','i','e','o','u']
            conlen = 0
            for p in word:
                if p not in vowel:
                    conlen += 1
                    #print p,conlen
                    if conlen >= n:
                        break
                else:
                    conlen = 0
            if conlen >= n:
                nval += 1
    print "Case #" + str(i+1) + ": " + str(nval)
