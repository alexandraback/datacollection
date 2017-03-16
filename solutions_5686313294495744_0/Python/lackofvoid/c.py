import itertools

if __name__ == "__main__":
    T = int(input())

    for i in range(1,T+1):
        N = int(input())
        topics = []
        for j in range(N):
            topics.append(input())

        for n in range(1,N):
            combs = itertools.combinations(topics, n)
            poss = False
            for reals in combs:
                # print(reals)
                freal = []
                sreal = []
                for r in reals:
                    f,s = r.split(" ")
                    freal.append(f)
                    sreal.append(s)
                poss = all( (t in reals) or (t.split(" ")[0] in freal and\
                        t.split(" ")[1] in sreal) for t in topics )
                if poss:
                    res = N - n
                    break
            if poss:
                break
        if not poss:
            res = 0

        # firsts = []
        # seconds = []
        # for t in topics:
            # f,s = t.split(" ")
            # firsts.append(f)
            # seconds.append(s)

        # # mult1st = 0
        # # mult2nd = 0
        # # for f in set(firsts):
            # # fc = firsts.count(f)
            # # if fc >= 2:
                # # mult1st += fc-1
        # # for s in set(seconds):
            # # sc = seconds.count(s)
            # # if sc >= 2:
                # # mult2nd += sc-1

        # mult1st = len(firsts) - len(set(firsts))
        # mult2nd = len(seconds) - len(set(seconds))

        # res = min(mult1st, mult2nd)

        print("Case #%i: %i" % (i, res))
        # print(firsts)
        # print(seconds)
