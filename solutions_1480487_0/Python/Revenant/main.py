import itertools
import numpy

file=open('input.txt','rt')
out_file = open('output.txt','wt')

test_cases = int(file.readline())

def powerset(s):
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

def solve(num_constants, judge_scores):

    votes = []
    sum_scores = float(sum(judge_scores))

    Z = numpy.zeros(shape=(num_constants, num_constants))
    A = numpy.matrix(Z,numpy.float64)
    Y = numpy.matrix(numpy.zeros(shape=(num_constants, 1)),numpy.float64)

    Y[0] = 1.0
    for i in range(0,num_constants):
        A[0, i] = 1.0

    for i in range(1,num_constants):
        Y[i] = (judge_scores[i] - judge_scores[0])

        A[i,0] = sum_scores
        A[i,i] = -sum_scores

    #print(A)
    #print(Y)

    X = numpy.array(A.getI() * Y)
    return list(X[:,0])



for test_case in range(0, test_cases):
    tokens = [int(x) for x in file.readline().split(' ')]

    num_constants = tokens.pop(0)
    judge_scores = tokens

    res = solve(num_constants, judge_scores)
    print('Case #{0}: {1}'.format(test_case+1, ' '.join(['{0:.8f}'.format(x*100) for x in res])))


out_file.flush()
out_file.close()