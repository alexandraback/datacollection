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
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    [omino_size, num_rows, num_columns] = [int(x) for x in line.split()]

    # WLOG, we can assume num_rows <= num_columns
    if num_rows > num_columns:
        temp = num_rows
        num_rows = num_columns
        num_columns = temp

    answer = "NONE"
    if (num_rows*num_columns)%omino_size != 0:
        answer = "RICHARD"
    elif omino_size == 1:
        answer = "GABRIEL"
    elif omino_size > num_rows and omino_size > num_columns:
        answer = "RICHARD"
    elif omino_size == 2:
        answer = "GABRIEL"
    elif omino_size == 3 and num_rows > 1:
        answer = "GABRIEL"
    elif omino_size == 3:
        answer = "RICHARD"
    # QUESTIONABLE!
    # 1x4 ==> Richard
    # 2x4 ==> Richard
    # 3x4 ==> Gabriel
    # 4x4 ==> Gabriel
    elif omino_size == 4 and num_rows > 2:
        answer = "GABRIEL"
    elif omino_size == 4:
        answer = "RICHARD"
    else:
        print("PROBLEM!!!!")

    print "Case #" + str(case_num+1) + ":", answer

