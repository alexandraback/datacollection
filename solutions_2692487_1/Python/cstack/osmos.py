from os import sys

def solve(A,motes):
    if len(motes) == 0:
        return 0
    if A > motes[0]:
        return solve(A+motes[0], motes[1:])
    if A == 1:
        return len(motes)
    additions_needed = 0
    new_A = A
    while new_A <= motes[0] and additions_needed < len(motes):
        new_A += new_A - 1
        additions_needed += 1
    if additions_needed >= len(motes):
        return len(motes)
    else:
        return solve(new_A+motes[0], motes[1:]) + additions_needed

num_cases = int(sys.stdin.readline())

for case in range(1,num_cases+1):

    (A,N) = [int(i) for i in sys.stdin.readline().split()]
    motes = [int(i) for i in sys.stdin.readline().split()]
    motes.sort()

    print "Case #"+str(case)+":",solve(A,motes)
