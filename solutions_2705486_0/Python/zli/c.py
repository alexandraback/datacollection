from collections import defaultdict
#import pickle
import cPickle as pickle

wdict = pickle.load(open("wdict.pkl"))
#print "Dictionary loaded"

for case in range(input()):
    print "Case #"+str(case+1)+":",
    message = raw_input()

    """
    words = open("garbled_email_dictionary.txt").read().split("\n")
    wbylen = []
    for i in xrange(11):
        wbl = [w for w in words if len(w) == i]
        wbylen.append(wbl)

    wdict = [defaultdict(lambda:[]) for i in xrange(11)]
    for w in words:
        print w
        for i,c in enumerate(w):
            letters = list(w)
            letters[i] = "*"
            neww = "".join(letters)
            if neww not in 
            wdict[len(w)]["".join(letters)].append(w)
    """

    #INF = ""
    INF = 4001

    def diff(w,x):
        d = 0
        last = -1
        for i,c in enumerate(w):
            if c != x[i]:
                d += 1
                if last>-1 and i-last<5:
                    return INF
                last = i
        return d

    def cost(w):
        mincost = INF
        for i,c in enumerate(w[:5]):
            letters = list(w[:5])
            letters[i] = "*"
            neww = "".join(letters)
            #print neww
            if neww in wdict:
                #print w,neww
                diffs = [diff(w,x) for x in wdict[neww] if len(x)==len(w)]
                if diffs:
                    mincost = min(mincost, min(diffs))
                #mincost = min(mincost, min([diff(w,x) for x in wdict[neww] if len(x)==len(w)],INF))
        return mincost
        #for i in xrange(len(w)):
        #    mincost = min(mincost, diff() for x in w[i]
        #return min(diff(w,x) for x in wbl)

    #opt = []
    val = [0 for i in xrange(len(message)+1)]
    val[0] = 0
    for i,c in enumerate(message):
        i = i+1
        val[i] = INF
        for ls in xrange(max(0,i-11),i):
            #print "ls",ls
            if val[ls]<INF:
                lsval = val[ls] + cost(message[ls:i])
                #print i,ls,lsval
                val[i] = min(val[i], lsval)
                #opt[i][ls] = val[ls] + cost(message[ls:])
                #val[i] = min(val[i],opt[i][ls])

    print val[-1]
