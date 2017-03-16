# returns answer.
def solve(num, scores):
    total = sum(scores, 0.0)
    save = total
    high = max(scores)
    answers = [0 for x in range(num)]
    i = 1
    while (i <= high and total > 0):
        j = 0
        p = 0
        while (j < num):
            if scores[j] < i:
                p += 1
            j +=1
        if p <= total:
            l = 1
        else: 
            l = (total/p)
        j = 0 
        while (j < num):
            if scores[j] < i:
                scores[j] += l
                answers[j] += l
                total -= l
            j += 1
        i += 1
    if total > 0:
        answers = map((lambda x: (x+total/num)), answers)
    answers = map((lambda x: (x/save * 100)), answers)
    return answers

# grab number of cases
cases = int(raw_input())

#array to store input values
inputs = []

#parse input, store in inputs array
for ncase in range(cases):
    stdin = raw_input()
    case = map(int, stdin.split(' '))
    num, scores = case[0], map(float, case[1:]) 
    inputs.append((ncase,num,scores))

# calculate answer
for case in inputs:
    ncase, num, scores = case
    ncase += 1
    solutions = solve(num, scores)
    solutions = map(str, solutions)
    print "Case #" + str(ncase) + ": " + " ".join(solutions)

