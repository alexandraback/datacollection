import sys

def readLine():
    return sys.stdin.readline()

def readLineAsInt():
    return int(readLine())

def readLineAsArray():
    return readLine().split()

def readLineAsIntArray():
    return [int(x) for x in readLineAsArray()]

def case(N, S, p, scores):
    #print scores
    if p == 0:
        return len(scores)
    elif p == 1:
        return len([x for x in scores if x > 0])
    
    candidate_score = 3 * p - 4
    #print candidate_score 
    safe_score = 3 * p - 2
    candidates = [x for x in scores if candidate_score <= x < safe_score ]
    #print candidates
    safe = [x for x in scores if  x >= safe_score ]
    #print safe
    lucky = len(candidates) if len(candidates) < S else S
    return len(safe) + lucky

T = readLineAsInt()
for i in range(T):
    arr = readLineAsIntArray()
    ret = case(arr[0], arr[1], arr[2], arr[3:])
    print "Case #%d: %d" % (i + 1, ret)