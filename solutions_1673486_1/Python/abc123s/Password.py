# solve the problem
def expectedValue(A, B, P):
    # precompute all the cumulative probabilties
    cprob = []
    prob1 = 1
    for x in range(A):
        prob1 *= P[x]
        cprob.append(prob1)
    # calculate the expected value of each of the solutions    
    sol1 = (B-A + 1) * prob1 + (B-A + B + 2) * (1 - prob1)
    sol3 = 2 + B
    sollist = [sol1, sol3]
    for x in range(A):
        sollist.append((2*x+B-A+1)*cprob[A-x-1] + (2*x+B-A+1+B+1) * (1 - cprob[A-x-1]))
    return min(sollist)

# grab number of cases
cases = int(raw_input())

# array to store input values
inputs = []

#parse input, store in inputs array
for ncase in range(cases):
    stdin = raw_input()
    case = map(int, stdin.split(' '))
    probabilities = map(float, raw_input().split(' '))
    inputs.append((ncase, case[0], case[1], probabilities))

# calculate answer
for case in inputs:
    ncase, A, B, probabilities = case
    print "Case #" + str(ncase + 1) + ": %.6f" % expectedValue(A, B, probabilities)
