#!/usr/bin/env python3

import sys

# Greedy function. Will try to use the surprise number of scores in the
# first score that has maximum value at least the threshold
def get_best(triplets, smax, threshold, surprising):
    t = None
    for i, j, k, m, s in triplets:
        if m >= threshold:
            if s == False:
                return (i, j, k, s)
            if surprising > 0:
                t = (i, j, k, s)
    return t

# Individual scores can't be more than 2 apart
def gen_triplets(score, threshold):
    triplets = []
    smax = 0
    for i in range(0, 11):
        for j in range(i, min(i + 3, 11)):
            for k in range(i, min(i + 3, 11)):
                if (i + j + k) == score:
                    m = max(i, j, k)
                    # Score can be ignored it the max value is
                    # smaller than the threshold
                    if m < threshold:
                        continue
                    smax = max(smax, m)
                    if k - i > 1 or j - i > 1:
                        triplets.append((i, j, k, m, True))
                    else:
                        triplets.append((i, j, k, m, False))
    #print("max is", smax)
    return triplets, smax

def googlers(scores, surprising, threshold):
    count = 0
    #print(scores, surprising, threshold)
    for googler in range(len(scores)):
        triplets, smax = gen_triplets(scores[googler], threshold)
        best = get_best(triplets, smax, threshold, surprising)
        #print("Best is", best)
        if best:
            count = count + 1
            if best[3] == True:
                surprising = surprising - 1
    return count

if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for case in range(1, ncases + 1):
        line = sys.stdin.readline().strip().split(' ')
        nsurprising = int(line[1])
        threshold = int(line[2])
        scores = [int(x) for x in line[3:]]
        print("Case #", case, ": ", googlers(scores, nsurprising, threshold), sep="")
