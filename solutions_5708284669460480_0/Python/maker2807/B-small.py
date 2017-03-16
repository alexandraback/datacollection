T = input()
for t in range(T):
    s = raw_input()
    (K,L,S) = map(int,s.split())
    keyboard = raw_input()
    target = raw_input()

    res = 0.0
    if (set(target) <= set(keyboard)):
        maxc = 0
        words = [""]
        for i in range(S):
            newWords = []
            for w in words:
                for l in keyboard:
                    newWords.append(w+l)
            words = newWords
        #print words

        for w in words:
            c = len([i for i in range(len(w)) if w[i:].startswith(target)])
            maxc = max(maxc,c)
            res+=c

        res/=len(words)
        res = maxc-res

    print "Case #%d:"%(t+1,), res
    
