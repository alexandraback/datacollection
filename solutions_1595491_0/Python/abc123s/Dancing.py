# returns whether a score of high is achievable with a total score
# of total, and a maximum difference of dif.
def achievable(total, high, dif):
    if dif > high:
        dif = high
    return ((high*3 - 2*dif) <= total)

# grab number of cases
cases = int(raw_input())

#array to store input values
inputs = []

#parse input, store in inputs array
for ncase in range(cases):
    stdin = raw_input()
    case = map(int, stdin.split(' '))
    num, surprising, best, scores = case[0], case[1], case[2], case[3:] 
    inputs.append((ncase,num,surprising,best,scores))

# calculate answer
for case in inputs:
    ncase, num, surprising, best, scores = case
    ncase += 1
    maxGooglers = 0
    remainingscores = [] 
    # check whether high can be achieved without surprising
    for score in scores:
        if achievable(score, best, 1):
            maxGooglers += 1
        else:
            remainingscores.append(score)
    # check whether high can be achieved with surprising
    for score in remainingscores:
        if surprising > 0 and achievable(score, best, 2):
            maxGooglers += 1
            surprising -= 1
    print "Case #" + str(ncase) + ": " + str(maxGooglers) 

