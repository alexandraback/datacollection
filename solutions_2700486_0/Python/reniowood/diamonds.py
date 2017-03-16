T = input()

for t in range(1, T+1):
    N, X, Y = [int(data) for data in raw_input().split()]

    prob = {(0, 0): 1.0}

    for n in range(N-1):
        if len([coord for coord in prob if prob[coord] < 1]) == 0:
            highest = [data[0] for data in prob.items() if data[0][1] == max([key[1] for key in prob])]
            highest.sort()
            if len(highest) == 1:
                leftmost = min([key[0] for key in prob]) 
                rightmost = max([key[0] for key in prob])

                prob[(leftmost-2, 0)] = 0.5
                prob[(rightmost+2, 0)] = 0.5
            else:
                for i in range(len(highest)-1):
                    prob[(highest[i][0]+1, highest[i][1]+1)] = 1/float(len(highest)-1)
        else:
            temp = [data[0] for data in prob.items() if data[1] < 1]
            candidates = []
            for candidate in temp:
                if (candidate[0]+1, candidate[1]+1) not in temp and (candidate[0]+2, candidate[1]) in prob and prob[(candidate[0]+2, candidate[1])] == 1.0:
                    candidates.append((candidate[0]+1, candidate[1]+1))
                if (candidate[0]-1, candidate[1]+1) not in temp and (candidate[0]-2, candidate[1]) in prob and prob[(candidate[0]-2, candidate[1])] == 1.0 and (candidate[0]-1, candidate[1]+1) not in candidates:
                    candidates.append((candidate[0]-1, candidate[1]+1))
            candidates = candidates + temp

            for candidate in candidates:
                if candidate not in prob:
                    prob[candidate] = 1/float(len(candidates))
                else:
                    prob[candidate] += 1/float(len(candidates))
                    if prob[candidate] > 1:
                        prob[candidate] = 1

    print "Case #%d: %.10f" % (t, prob[(X, Y)] if (X, Y) in prob else 0)
