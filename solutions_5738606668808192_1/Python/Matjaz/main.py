import itertools


print "Case #1:"

N = int(raw_input())
J = int(raw_input())

def solutionGenerator(N,numberofOnes):
    answer = [(0 , N-1)]

    even = []
    odd  = []

    for i in range(1,N-1):
        if i % 2 == 0:
            even.append(i)
        else :
            odd.append(i)

    for choiceOdd in itertools.combinations(odd,(numberofOnes - 2) / 2):
        for choicvEven in itertools.combinations(even, (numberofOnes - 2) / 2):
            yield answer + [choiceOdd] + [choicvEven]

def generateBlank(N):
    result = []
    for i in range(N):
        result.append("0")
    return result

solutions = solutionGenerator(N, 6)

divisors = "3 2 3 2 7 2 3 2 3"

for i in range(J):
    output = generateBlank(N)
    solution = solutions.next()

    for tuple in solution:
        for index in tuple:
            output[index] = "1"

    output = output[::-1]

    print "".join(output),divisors
