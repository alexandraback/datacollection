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


table_file = open( "full_table" )
answers = ["INSOMNIA" for i in range((10**6)+1)]
for i in range((10**6)+1):
    answers[i] = int(table_file.readline().strip())
answers[0] = "INSOMNIA"

f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    N = int(line)

    print "Case #" + str(case_num+1) + ":", answers[N]

