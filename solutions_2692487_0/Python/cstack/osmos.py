from os import sys

def solve(A,motes):
    if len(motes) == 0:
        return 0
    if A > motes[0]:
        return solve(A+motes[0], motes[1:])
    if A > 1:
        try_adding = solve(A,[A-1]+motes)
        try_removing = solve(A,motes[:-1])
        return min(try_adding, try_removing) + 1
    else:
        return solve(A,motes[:-1]) + 1

num_cases = int(sys.stdin.readline())

for case in range(1,num_cases+1):

    (A,N) = [int(i) for i in sys.stdin.readline().split()]
    motes = [int(i) for i in sys.stdin.readline().split()]
    motes.sort()

    print "Case #"+str(case)+":",solve(A,motes)
