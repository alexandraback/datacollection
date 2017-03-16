# Dancing With the Googlers

possible_scores = {0: [[0, 0, 0]], 1: [[0, 0, 1]], 2: [[0, 0, 2], [0, 1, 1]], 3: [[0, 1, 2], [1, 1, 1]], 4: [[0, 2, 2], [1, 1, 2]], 5: [[1, 1, 3], [1, 2, 2]], 6: [[1, 2, 3], [2, 2, 2]], 7: [[1, 3, 3], [2, 2, 3]], 8: [[2, 2, 4], [2, 3, 3]], 9: [[2, 3, 4], [3, 3, 3]], 10: [[2, 4, 4], [3, 3, 4]], 11: [[3, 3, 5], [3, 4, 4]], 12: [[3, 4, 5], [4, 4, 4]], 13: [[3, 5, 5], [4, 4, 5]], 14: [[4, 4, 6], [4, 5, 5]], 15: [[4, 5, 6], [5, 5, 5]], 16: [[4, 6, 6], [5, 5, 6]], 17: [[5, 5, 7], [5, 6, 6]], 18: [[5, 6, 7], [6, 6, 6]], 19: [[5, 7, 7], [6, 6, 7]], 20: [[6, 6, 8], [6, 7, 7]], 21: [[6, 7, 8], [7, 7, 7]], 22: [[6, 8, 8], [7, 7, 8]], 23: [[7, 7, 9], [7, 8, 8]], 24: [[7, 8, 9], [8, 8, 8]], 25: [[7, 9, 9], [8, 8, 9]], 26: [[8, 8, 10], [8, 9, 9]], 27: [[8, 9, 10], [9, 9, 9]], 28: [[8, 10, 10], [9, 9, 10]], 29: [[9, 10, 10]], 30: [[10, 10, 10]]}

def checkScores(scores, n):
    if max(scores) >= n:
        return True
    return False

def isSurprising(lst):
    if abs(lst[0] - lst[1]) == 2:
        return True
    if abs(lst[0] - lst[2]) == 2:
        return True
    if abs(lst[1] - lst[2]) == 2:
        return True
    return False

i = open("B-large.in", "r")
o = open("B-large.out", "w")

T = int(i.readline())

for c in range(1, T + 1):
    params = i.readline().replace('\n','').split(' ')

    N = int(params[0])
    S = int(params[1])
    p = int(params[2])
    tN = map(int, params[3:])
    
    surprising, normal = [], []
    for ti in tN:
        for scores in possible_scores[ti]:
            if checkScores(scores, p):
                if isSurprising(scores):
                    surprising.append(ti)
                else:
                    normal.append(ti)

    result, s, tN = 0, 0, sorted(tN)
    for ti in tN:
        if ti in normal:
            result += 1
            continue
        if ti in surprising and s < S:
            result += 1
            s += 1
            continue

    o.write("Case #{0}: {1}\n".format(c, result))

i.close()
o.close()