#!/usr/bin/env python
# -*- coding: utf-8 -*-

if __name__ == "__main__":
    testcases = int(raw_input())
    for caseNr in xrange(1, testcases+1):
        J,P,S,K = map(int, raw_input().split(" "))

        seenComb = {}
        output1 = []
        done = False
        for j in range(J):
            for p in range(P):
               for s in range(S):

                    if(not "j%dp%d"%(j,p) in seenComb):
                        seenComb["j%dp%d"%(j,p)]=0
                    if(not "j%ds%d"%(j,s) in seenComb):
                        seenComb["j%ds%d"%(j,s)]=0
                    if(not "p%ds%d"%(p,s) in seenComb):
                        seenComb["p%ds%d"%(p,s)]=0
                    seenComb["j%dp%d"%(j,p)]+=1
                    seenComb["j%ds%d"%(j,s)]+=1
                    seenComb["p%ds%d"%(p,s)]+=1

                    if seenComb["j%dp%d"%(j,p)] > K or seenComb["j%ds%d"%(j,s)] > K or seenComb["p%ds%d"%(p,s)] > K:
                        seenComb["j%dp%d" % (j, p)] -= 1
                        seenComb["j%ds%d" % (j, s)] -= 1
                        seenComb["p%ds%d" % (p, s)] -= 1
                        continue

                    output1.append("%d %d %d"%(j+1,p+1,s+1))
        seenComb = {}
        output2 = []
        done = False

        for j in range(J):
            for s in range(S):
                for p in range(P):

                    if (not "j%dp%d" % (j, p) in seenComb):
                        seenComb["j%dp%d" % (j, p)] = 0
                    if (not "j%ds%d" % (j, s) in seenComb):
                        seenComb["j%ds%d" % (j, s)] = 0
                    if (not "p%ds%d" % (p, s) in seenComb):
                        seenComb["p%ds%d" % (p, s)] = 0
                    seenComb["j%dp%d" % (j, p)] += 1
                    seenComb["j%ds%d" % (j, s)] += 1
                    seenComb["p%ds%d" % (p, s)] += 1

                    if seenComb["j%dp%d" % (j, p)] > K or seenComb["j%ds%d" % (j, s)] > K or seenComb[
                                "p%ds%d" % (p, s)] > K:
                        seenComb["j%dp%d" % (j, p)] -= 1
                        seenComb["j%ds%d" % (j, s)] -= 1
                        seenComb["p%ds%d" % (p, s)] -= 1
                        continue

                    output2.append("%d %d %d" % (j + 1, p + 1, s + 1))

        seenComb = {}
        output3 = []
        done = False
        for s in range(S):
            for p in range(P):
                for j in range(J):

                    if (not "j%dp%d" % (j, p) in seenComb):
                        seenComb["j%dp%d" % (j, p)] = 0
                    if (not "j%ds%d" % (j, s) in seenComb):
                        seenComb["j%ds%d" % (j, s)] = 0
                    if (not "p%ds%d" % (p, s) in seenComb):
                        seenComb["p%ds%d" % (p, s)] = 0
                    seenComb["j%dp%d" % (j, p)] += 1
                    seenComb["j%ds%d" % (j, s)] += 1
                    seenComb["p%ds%d" % (p, s)] += 1

                    if seenComb["j%dp%d" % (j, p)] > K or seenComb["j%ds%d" % (j, s)] > K or seenComb[
                                "p%ds%d" % (p, s)] > K:
                        seenComb["j%dp%d" % (j, p)] -= 1
                        seenComb["j%ds%d" % (j, s)] -= 1
                        seenComb["p%ds%d" % (p, s)] -= 1
                        continue

                    output3.append("%d %d %d" % (j + 1, p + 1, s + 1))

        seenComb = {}
        output4 = []
        done = False
        for s in range(S):
            for j in range(J):
                for p in range(P):

                    if (not "j%dp%d" % (j, p) in seenComb):
                        seenComb["j%dp%d" % (j, p)] = 0
                    if (not "j%ds%d" % (j, s) in seenComb):
                        seenComb["j%ds%d" % (j, s)] = 0
                    if (not "p%ds%d" % (p, s) in seenComb):
                        seenComb["p%ds%d" % (p, s)] = 0
                    seenComb["j%dp%d" % (j, p)] += 1
                    seenComb["j%ds%d" % (j, s)] += 1
                    seenComb["p%ds%d" % (p, s)] += 1

                    if seenComb["j%dp%d" % (j, p)] > K or seenComb["j%ds%d" % (j, s)] > K or seenComb[
                                "p%ds%d" % (p, s)] > K:
                        seenComb["j%dp%d" % (j, p)] -= 1
                        seenComb["j%ds%d" % (j, s)] -= 1
                        seenComb["p%ds%d" % (p, s)] -= 1
                        continue

                    output4.append("%d %d %d" % (j + 1, p + 1, s + 1))

        seenComb = {}
        output5 = []
        done = False
        for p in range(P):
            for j in range(J):
                for s in range(S):

                    if (not "j%dp%d" % (j, p) in seenComb):
                        seenComb["j%dp%d" % (j, p)] = 0
                    if (not "j%ds%d" % (j, s) in seenComb):
                        seenComb["j%ds%d" % (j, s)] = 0
                    if (not "p%ds%d" % (p, s) in seenComb):
                        seenComb["p%ds%d" % (p, s)] = 0
                    seenComb["j%dp%d" % (j, p)] += 1
                    seenComb["j%ds%d" % (j, s)] += 1
                    seenComb["p%ds%d" % (p, s)] += 1

                    if seenComb["j%dp%d" % (j, p)] > K or seenComb["j%ds%d" % (j, s)] > K or seenComb[
                                "p%ds%d" % (p, s)] > K:
                        seenComb["j%dp%d" % (j, p)] -= 1
                        seenComb["j%ds%d" % (j, s)] -= 1
                        seenComb["p%ds%d" % (p, s)] -= 1
                        continue

                    output5.append("%d %d %d" % (j + 1, p + 1, s + 1))

        seenComb = {}
        output6 = []
        done = False
        for p in range(P):
            for s in range(S):
                for j in range(J):

                    if (not "j%dp%d" % (j, p) in seenComb):
                        seenComb["j%dp%d" % (j, p)] = 0
                    if (not "j%ds%d" % (j, s) in seenComb):
                        seenComb["j%ds%d" % (j, s)] = 0
                    if (not "p%ds%d" % (p, s) in seenComb):
                        seenComb["p%ds%d" % (p, s)] = 0
                    seenComb["j%dp%d" % (j, p)] += 1
                    seenComb["j%ds%d" % (j, s)] += 1
                    seenComb["p%ds%d" % (p, s)] += 1

                    if seenComb["j%dp%d" % (j, p)] > K or seenComb["j%ds%d" % (j, s)] > K or seenComb[
                                "p%ds%d" % (p, s)] > K:
                        seenComb["j%dp%d" % (j, p)] -= 1
                        seenComb["j%ds%d" % (j, s)] -= 1
                        seenComb["p%ds%d" % (p, s)] -= 1
                        continue

                    output6.append("%d %d %d" % (j + 1, p + 1, s + 1))

        if len(output1) >= len(output2) and len(output1) >= len(output3) and len(output1) >= len(output4) and len(output1) >= len(output5) and len(output1) >= len(output6):
            output = output1
        elif len(output2) >= len(output1) and len(output2) >= len(output3) and len(output2) >= len(output4) and len(output2) >= len(output5) and len(output2) >= len(output6):
            output = output2
        elif len(output3) >= len(output1) and len(output3) >= len(output2) and len(output3) >= len(output4) and len(output3) >= len(output5) and len(output3) >= len(output6):
            output = output3
        elif len(output4) >= len(output2) and len(output4) >= len(output3) and len(output4) >= len(output1) and len(output4) >= len(output5) and len(output4) >= len(output6):
            output = output4
        elif len(output5) >= len(output1) and len(output5) >= len(output3) and len(output5) >= len(output4) and len(output5) >= len(output2) and len(output5) >= len(output6):
            output = output5
        elif len(output6) >= len(output1) and len(output6) >= len(output2) and len(output6) >= len(output3) and len(output6) >= len(output4) and len(output6) >= len(output5):
            output = output6


        print("Case #%i: %s" % (caseNr, len(output)))
        for o in output:
            print o
