#!/usr/bin/env python3

def solve(b, m):
    #print(b, m,)
    if 2**(b-2) < m:
        return 'IMPOSSIBLE'
    conn = [False]*(b-1)
    i = b-2
    while i >= 0:
        if i == 0:
            ways = 1
        else:
            ways = 2**(i-1)
        if m >= ways:
            m -= ways
            conn[i] = True
        i -= 1
    #print(conn)
    matrix = []
    for i in range(b-1):
        c = "1" if conn[i] else "0"
        matrix.append("0"*(i+1)+("1"*(b-i-2))+c)
    matrix.append(b*"0")
    return "POSSIBLE\n" + '\n'.join(matrix)


testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
