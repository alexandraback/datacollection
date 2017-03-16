with open("B-large.in") as fin:
    with open("B.out", "w") as fout:
        T = int(fin.readline())
        for q in range(T):
            print(q)
            N = int(fin.readline().strip())
            oneStars = {} # level -> req'd
            twoStars = {}
            for r in range(N):
                line = fin.readline().strip()
                (a, b) = tuple(int(x) for x in line.split(" "))
                oneStars[r] = a
                twoStars[r] = b
            oneKeys = sorted(oneStars.keys(), key=lambda a:oneStars[a])
            twoKeys = sorted(twoStars.keys(), key=lambda a:twoStars[a])
            #print(oneKeys)
            #print(twoKeys)
            twoIndex = 0
            oneIndex = 0
            stars = 0
            attempts = 0
            while len(twoStars) > 0:
                didSomething = False
                #print("d ", twoIndex, len(twoKeys), twoStars[twoKeys[twoIndex]], stars)
                while twoIndex < len(twoKeys) and twoStars[twoKeys[twoIndex]] <= stars:
                    if twoKeys[twoIndex] in oneStars:
                        stars += 2
                        #print("x2 ", twoKeys[twoIndex], " ", stars)
                    else:
                        stars += 1
                        #print("x1(2) ", twoKeys[twoIndex], " ", stars)
                    attempts += 1
                    del twoStars[twoKeys[twoIndex]]
                    twoIndex += 1
                    didSomething = True
                #print("d", oneIndex, oneKeys[oneIndex])
                if oneIndex < len(oneKeys) and oneStars[oneKeys[oneIndex]] <= stars:
                    if oneKeys[oneIndex] in twoStars:
                        stars += 1
                        attempts += 1
                        #print("x1 ", oneKeys[oneIndex], " ", stars)
                    del oneStars[oneKeys[oneIndex]]
                    oneIndex += 1
                    didSomething = True
                if not didSomething:
                    break
            if len(twoStars) > 0:
                result = "Too Bad"
            else:
                result = str(attempts)
            fout.write("Case #" + str(q + 1) + ": " + result + "\n")
