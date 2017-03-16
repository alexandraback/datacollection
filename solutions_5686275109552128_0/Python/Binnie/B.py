import sys

MAX_PLATES = 9
MAX_POSSIBLE_SCORE = 1000*1000


def get_best_score(diners_plates):
    best_score = MAX_POSSIBLE_SCORE
    for i in range(1, MAX_PLATES + 1):
        score = i
        for num_plates in diners_plates:
            if num_plates > i:
                score += (num_plates-1)/i
        best_score = min(best_score, score)

    return best_score


f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    D = int(f.readline().strip())
    diners = map(int, f.readline().strip().split())

    print "Case #%d: " % (test + 1), get_best_score(diners)