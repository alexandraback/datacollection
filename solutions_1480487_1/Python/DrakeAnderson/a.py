from sys import stdin

t = int(stdin.readline()) + 1
for i in range(1, t):
    str_array = stdin.readline().split(" ")
    n = int(str_array[0])
    scores = list()
    score_sum = 0
    for j in range(1, n + 1):
        scores.append(int(str_array[j]))
        score_sum += int(str_array[j])
    sorted_score = sorted(scores)
    score_array = list()
    score_string = "Case #%d: " % i
    for score in scores:
        sorted_score = sorted(scores)
        sorted_score.remove(score)
        k = 0
        external_count = 1
        temp_max_score = score_sum
        needed_score = 0
        while(k < len(sorted_score) and sorted_score[k] <= score):
            if score > sorted_score[k]:
                temp_max_score -= (score - sorted_score[k])
            external_count += 1
            k += 1
        #print "%d %d %d %d" % (temp_max_score,score,external_count,needed_score)
        while temp_max_score > 0:
            if k < len(sorted_score):
                diff = (sorted_score[k] - score) * external_count
                if temp_max_score < diff:
                    needed_score += temp_max_score * 1.0 / external_count
                    temp_max_score = 0
                else:
                    temp_max_score -= diff
                    needed_score += diff * 1.0 / external_count
                    score = sorted_score[k]
                    k += 1
                    external_count += 1
            else:
                needed_score += temp_max_score * 1.0 / external_count
                temp_max_score = 0
            #print "%d %d %d %d" % (temp_max_score,score,external_count,needed_score)
        score_array.append(needed_score * 1.0 / score_sum)
        score_string += str(needed_score * 100.0 / score_sum) + " "
    print score_string
