#!/usr/bin/python

from operator import itemgetter


def looper(stars, rounds, levels, lev):
                        for e in range(levels):
                            for f in range(levels):
                                if lev[f][1]<= stars and lev[f][2] <2:
                                    if lev[f][1] <= stars and lev[f][2] <1:
                                        stars = stars+2
                                        lev[f][2] = 2
                                    else:
                                        stars = stars+1
                                        lev[f][2] += 1
                                    rounds = rounds+1
                                    print(lev[f])
                                    return(stars, rounds)
                            if lev[e][0] <= stars and lev[e][2] < 1:
                                if lev[e][1] <= stars and lev[e][2] <1:
                                    stars = stars+2
                                    lev[e][2] = 2
                                else:
                                    stars = stars+1
                                    lev[e][2] += 1
                                rounds = rounds+1
                                print(lev[e])
                                return(stars, rounds)
                        return(-1, -1)


try:
    with open("B-small-attempt1.in") as inFile, open("output.txt", "w") as outFile:
            cases = int(inFile.readline().strip())
            for c in range(cases):
                    levels = int(inFile.readline().strip())
                    lev = []
                    stars = 0
                    rounds = 0
                    for l in range(levels):
                        arr = (inFile.readline().strip().split(" "))
                        arr2 = [int(arr[0]), int(arr[1]), 0]
                        lev.append(arr2)
                        lev.sort(key=itemgetter(1, 0), reverse=True)
                    while stars < levels*2 and stars != -1:
                        (stars, rounds) = looper(stars, rounds, levels, lev)
                        if stars == -1:
                            outFile.write("Case #" + str(c+1) +": Too Bad \n")
                    if stars == levels*2:
                        outFile.write("Case #" + str(c+1) + ": " + str(rounds) + "\n")
except IOError as err:
    print("File error: " + str(err))
