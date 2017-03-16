with open('B-large.in', 'r+b') as f:
    T = int(f.readline().strip())
    for i in range(1, T+1):
        K, L, S = map(int, f.readline().strip().split())
        keyboard = f.readline().strip()
        target = f.readline().strip()

        isPossible = all([c in keyboard for c in target])
        if not isPossible:
            print 'Case #%d: 0.0' % i
            continue

        possibleOverlapStarts = [j+1 for (j, c) in enumerate(target[1:]) if c == target[0]]
        maxOverlapLength = 0
        maxOverlapStr = ''
        for p in possibleOverlapStarts:
            possibleOverlapLength = L - p
            if possibleOverlapLength > maxOverlapLength:
                if target[p:] == target[0:possibleOverlapLength]:
                    maxOverlapLength = possibleOverlapLength
                    maxOverlapStr = target[p:]

        probs = {}
        for c in keyboard:
            probs[c] = 1.0*keyboard.count(c)/K

        bringBananas = 1.0 + (S-L)/(L-maxOverlapLength)
        expectedBananasOneTime = 1.0
        for c in target:
            expectedBananasOneTime *= probs[c]
        expectedBananas = (S-L+1)* expectedBananasOneTime

        print "Case #%d: %f" % (i, bringBananas - expectedBananas)
        # print keyboard, target, S
        # print bringBananas
        # print expectedBananasOneTime
        # print expectedBananas
