#!/usr/bin/python

import sys

def factorial( n ):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)


def nchoosek( n, k ):
    #return factorial(n)/(factorial(k)*factorial(n-k))
    answer = 1
    for i in range(1,k+1):
        answer *= (n - (k - i))
        answer /= i
    return answer


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for case_num in range(num_cases):
    S = f.readline().strip()
    if len(S) <= 0:
        continue
    answer = []
    for letter in S:
        if len(answer) == 0:
            answer.append(letter)
        elif letter < answer[0]:
            answer.append(letter)
        else:
            answer.insert(0,letter)


    print "Case #" + str(case_num+1) + ":", "".join(answer)

