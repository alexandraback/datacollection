def better_score(score1, score2):
    coders1, jammers1 = score1.split()
    coders2, jammers2 = score2.split()
    coders1 = int(coders1)
    coders2 = int(coders2)
    jammers1 = int(jammers1)
    jammers2 = int(jammers2)
    if abs(coders1-jammers1) < abs(coders2-jammers2):
        return score1
    elif abs(coders1-jammers1) > abs(coders2-jammers2):
        return score2
    elif coders1 < coders2:
        return score1
    elif coders1 > coders2:
        return score2
    elif jammers1 < jammers2:
        return score1
    else:
        return score2

def solve(score):
    if score.count('?') == 0:
        return score
    best_score = list(score)
    for i in range(0, len(best_score)):
        if best_score[i] == '?':
            best_score[i] = '0'
    best_score = "".join(best_score)
    for i in range(0, len(score)):
        score_copy = list(score)
        if score[i] == '?':
            for j in range(0, 10):
                score_copy[i] = str(j)
                solved = solve("".join(score_copy))
                best_score = better_score(best_score, solved)
            break
    return best_score

T = int(input())
for t in range(0, T):
    print("Case #" + str(t+1) + ": " + solve(input()))
