
def detOverlap(w):
    overlap = 0

    cont = 1
    i = 0
    ans = 0
    length = len(w)
    while i < length-1:
        if w[0:i+1] == w[length-(i+1):]:
            ans = i + 2
        i += 1

    if ans > 0:
        ans -= 1

    return ans


f = open('B-small-attempt1.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    s = f.readline()
    s = s.split()
    s = map(int, s)
    K = s[0] #number of keys
    L = s[1] #length of target word
    S = s[2] #length of string

    s = f.readline()
    keys = list(s)
    keys.pop()
    s = f.readline()
    s = s[:-1]
    word = s
    wordchars = list(word)


    # Step 1: Count keys
    key = []
    for i in range(0, 26):
        key.append(0)
    for c in keys:
        key[ord(c)-ord('A')] += 1
    
    # Step 2: Check if word is even possible to be typed
    possible = 1
    for c in word:
        if key[ord(c)-ord('A')] == 0:
            possible = 0

    if possible == 0:
        ans = 0.0
        outline = "Case #%d: %f\n" % (t, ans)
        o.write(outline)
        continue

    # Step 3: Determine # bananas to bring
    overlap = detOverlap(word)
    nBananas = 1 + (S - L) / (L - overlap)
    #print word, nBananas

    # Step 4: Calculate expected number of words
    pWhole = 1.0
    for i in range(0, L):
        pWhole *= key[ord(word[i])-ord('A')] / float(K)
    pOverlap = int(overlap != 0)
    for i in range(L-overlap, L):
        pOverlap *= key[ord(word[i])-ord('A')] / K


    ans = 0
    for i in range(0, S - L + 1):
        temp1 = pWhole
        if overlap != 0:
            #temp1 *= 1 - key[ord(word[L-overlap])-ord('A')] / K
            nPossibleChains = 1 + (S - i - L) / (L - overlap)
            print nPossibleChains
            for j in range(2, nPossibleChains):
                temp1 += j * pOverlap
        ans += temp1

    ans = nBananas - ans
    print word, keys, overlap, pWhole, pOverlap, ans
                     
    outline = "Case #%d: %f\n" % (t, ans)
    o.write(outline)

o.close()
