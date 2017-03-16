filename = "A-small-attempt5"
infile = open("{}.in".format(filename))
outfile = open("{}.out".format(filename), 'w')

T = int(infile.readline())
for t in range(1,T+1):
    scores = [int(x) for x in infile.readline().strip().split()]
    scores.pop(0)
    X = sum(scores)

    ans = []
    for contestant in scores:
        if contestant == X:
            ans.append(0.0)
            continue

        hi = 1.0
        lo = 0.0
        P = 0.5
        while abs(hi-lo) > 0.000000000001:
            if contestant + P*X >= ((X-contestant) + (1-P)*X)/(len(scores)-1):
                hi = P
            else:
                lo = P
            P = (lo+hi)/2.0
        ans.append(100*P)

    final = ["{0:.6f}".format(x) for x in ans]
    outfile.write("Case #{}: {}\n".format(t, " ".join(final)))
    print("Case #{}: {}".format(t, " ".join(final)))
    
infile.close()
outfile.close()