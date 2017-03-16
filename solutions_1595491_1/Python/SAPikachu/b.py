import sys

SATISFIED = 0
SATISFIED_SURPRISING = 1
NOT_SATISFIED = 2

def check_score(total_score, lower_bound):
    avg = total_score // 3
    max_score = avg
    mod = total_score % 3

    if mod != 0:
        max_score += 1

    if max_score >= lower_bound:
        return SATISFIED

    if max_score == 0:
        return NOT_SATISFIED

    if mod in [0, 2]:
        max_score += 1

    if max_score >= lower_bound:
        return SATISFIED_SURPRISING

    return NOT_SATISFIED

def solve(input):
    params = [int(x) for x in input.split(" ")]
    count = params[0]
    surprising = params[1]
    score_lower_bound = params[2]
    scores = params[3:]

    satisfied_count = 0

    for score in scores:
        result = check_score(score, score_lower_bound)
        if result == SATISFIED:
            satisfied_count += 1
        elif result == SATISFIED_SURPRISING:
            if surprising > 0:
                surprising -= 1
                satisfied_count += 1

    return satisfied_count

def run():
    cases = int(sys.stdin.readline().strip())
    for i in range(cases):
        print("Case #{}: {}".format(i + 1, solve(sys.stdin.readline().strip())))

if __name__ == "__main__":
    run()

