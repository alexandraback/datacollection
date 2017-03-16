import sys
import numpy as np

def log(*args, sep=" ", end="\n", file= sys.stderr, flush= False):
    file.write(sep.join(str(a) for a in args) + end)
    if flush:
        file.flush()


def minEncounters(hikers):
    assert len(hikers) == 2
    slower= hikers[0] if hikers[0]["period"] >= hikers[1]["period"] else hikers[1]
    faster= hikers[1] if slower is hikers[0] else hikers[0]
    tRoundSlower= (360 - slower["start"]) * slower["period"]
    if faster["start"] + tRoundSlower / faster["period"] < 720:
        return 0
    else:
        return 1

if __name__ == "__main__":
    nCases= int(input())
    for iCase in range(1, nCases + 1):
        n= int(input())
        hikers= []
        for _ in range(n):
            d, h, m= map(int, input().split())
            for i in range(h):
                hikers.append({"start": d, "period": m + i})
        
        result= minEncounters(hikers)

        print("Case #{:d}: {:d}".format(iCase, result))
