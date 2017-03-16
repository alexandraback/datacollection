#!/usr/bin/python
import sys

def main(size):
	"""
	@param size = string; small or large
	"""
	infile = size + "_b.in"

	output = ""

	with open(infile) as file:
		num_cases = int(file.readline())
		for case in range(1, num_cases+1):
			coders_score, jammers_score = find_scores(file.readline().strip().split(" "))
			output += "Case #%s: %s %s\n" % (case, coders_score, jammers_score)

	with open(size + "_b.out", 'w') as outfile:
		outfile.write(output)


def find_scores(scores):
    coders_score = scores[0]
    jammers_score = scores[1]
    for i in range(len(coders_score)):
        if coders_score[i] == jammers_score[i] \
        and coders_score[i] != "?":
            continue
        elif coders_score[i] != "?" and jammers_score[i] != "?":
            return base_case(coders_score, jammers_score)
        elif coders_score[i] == "?" and jammers_score[i] == "?":
            possible_scores = []
            for i,j in [(0,0), (0,1), (1,0)]:
                possible_scores.append(find_scores((coders_score.replace("?", str(i), 1), jammers_score.replace("?", str(j), 1))))
            return choose_best(possible_scores)
        elif coders_score[i] == "?":
            approx = int(jammers_score[i])
            possible_scores = []
            for i in [-1, 0, 1]:
                possible_scores.append(find_scores((coders_score.replace("?", str(max(min(approx+i, 9), 0)), 1), jammers_score)))
            return choose_best(possible_scores)
        else: # jammers_score[i] == "?"
            approx = int(coders_score[i])
            possible_scores = []
            for i in [-1, 0, 1]:
                possible_scores.append(find_scores((coders_score, jammers_score.replace("?", str(max(min(approx+i, 9), 0)), 1))))
            return choose_best(possible_scores)
    return coders_score, jammers_score


def base_case(coders_score, jammers_score):
    for i in range(len(coders_score)):
        if coders_score[i] == jammers_score[i]:
            continue
        else:
            if int(coders_score[i]) > int(jammers_score[i]):
                return coders_score.replace("?", "0"), jammers_score.replace("?", "9")
            else:
                return coders_score.replace("?", "9"), jammers_score.replace("?", "0")
    return coders_score, jammers_score


def choose_best(scores):
    potential_scores = []
    best_diff = smallest_coders_score = smallest_jammers_score = float('inf')
    best_coders_score_string = best_jammers_score_string = ""
    for score in scores:
        coders_score = int(score[0])
        jammers_score = int(score[1])
        diff = abs(coders_score - jammers_score)
        if diff < best_diff:
               best_diff = diff
               smallest_coders_score = coders_score
               smallest_jammers_score = jammers_score
               best_coders_score_string = score[0]
               best_jammers_score_string = score[1]
        elif diff == best_diff:
            if coders_score < smallest_coders_score:
               best_diff = diff
               smallest_coders_score = coders_score
               smallest_jammers_score = jammers_score
               best_coders_score_string = score[0]
               best_jammers_score_string = score[1]
            elif coders_score == smallest_coders_score:
                if jammers_score < smallest_jammers_score:
                    best_diff = diff
                    smallest_coders_score = coders_score
                    smallest_jammers_score = jammers_score
                    best_coders_score_string = score[0]
                    best_jammers_score_string = score[1]
    return best_coders_score_string, best_jammers_score_string


if __name__ == "__main__":
	main(sys.argv[1])

