import functools
import itertools


fn = 'B-large'
input = open(fn+'.in','r')
output = open(fn+'.out', 'w')

def solve(case):
    N, X, Y = [int(n) for n in input.readline().split()]
    #If X is negative then just flip it - will be same due to symmetry
    X = abs(X)

    prob = getProbability(N,X,Y)
    print("Case #{0}: {1}".format(case, prob), file=output)

def getProbability(N,X,Y):
    #Triangle 1 is the 0,0. Triangle 2 is the 5 numbers around it
    numLayers = int((X+Y)/2) + 1
    triangleNumber = numLayers * 2 - 1

    #Apex case handled differently
    if X == 0:
        diamondsForTriangle = triangleNumber*(triangleNumber + 1)/2
        if N >= diamondsForTriangle:
            return 1.0
        else:
            return 0.0
    else:
        diamondsForInnerTriangle = int((triangleNumber-1)*(triangleNumber - 2)/2)
        if N <= diamondsForInnerTriangle: #not enough diamond drops to start doing the layer
            return 0.0

        diamondsRemaining = N - diamondsForInnerTriangle
        diamondsOnSideRequired = Y + 1 #If on Y=2, then need 3 diamonds to fall on this side to get it
        if diamondsRemaining < diamondsOnSideRequired:
            return 0.0
        elif diamondsRemaining >= triangleNumber - 1 + diamondsOnSideRequired: #Enough diamonds to fill up other side and then get high enough for us
            return 1.0
        else: #Assume we are on right side. Probability of diamondsOnSide or more 'rights'
            invprob = prob(diamondsOnSideRequired-1, 0.5, diamondsRemaining)
            return 1 - invprob

def factorial(n):
    if n < 2: return 1
    return functools.reduce(lambda x, y: x*y, range(2, int(n)+1))

#Cumulative probability of getting up to s successes with p probability and n trials
def prob(s, p, n):
    x = 1 - p

    a = n - s
    b = s + 1

    c = a + b - 1

    prob = 0

    for j in range(a, c + 1):
        prob += factorial(c) / (factorial(j)*factorial(c-j)) \
                * x**j * (1 - x)**(c-j)

    return prob


import time
start = time.clock()

T = int(input.readline())
for i in range(1,T+1):
    solve(i)

print("{0} milliseconds".format((time.clock() - start) * 1000))
