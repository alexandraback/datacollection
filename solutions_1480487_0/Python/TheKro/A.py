def ans(sc):
    total = sum(sc)
    newsc = [(sc[i], i) for i in range(len(sc))]
    sortsc = sorted(newsc, key = lambda x: x[0])
    sortsc.append((total+2*sortsc[-1][0], len(sc)))
    #print sortsc
    done = False
    place = 0
    used = [0.]*len(sc)
    usedtotal = 0.
    while not done:
        #print "val:", sortsc[place][0]
        if sortsc[place][0] < sortsc[place+1][0]:
            diff = sortsc[place+1][0] - sortsc[place][0]
            #print "diff:", diff
            if diff*(place+1) >= total - usedtotal:
                diff = (total - usedtotal)/(place+1)
                done = True
            for j in range(place+1):
                #print j
                used[j] += diff
            usedtotal += diff*(place+1)
        place += 1
    #print "used:", used
    used = [u/total for u in used]
    #print used
    res = [(used[i], sortsc[i][1]) for i in range(len(used))]
    newres = sorted(res, key = lambda x: x[1])
    return [100*n[0] for n in newres]

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T+1):
        vals = map(int, raw_input().split())
        N, scores = vals[0], vals[1:]
        print "Case #"+str(t)+":",
        for j in ans(map(float, scores)):
            print j,
        print
