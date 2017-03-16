
fn = 'A-small-attempt0'
input = open(fn+'.in','r')
output = open(fn+'.out', 'w')

def solve(case):
    A, N = [int(n) for n in input.readline().split()]
    S = [int(n) for n in input.readline().split()]

    S.sort()

    #See what max size we can get to
    helpGiven = 0

    ans = TrySolve(S, 0, len(S), A)

    print("Case #{0}: {1}".format(case, ans), file=output)

#i, j denote start and end of motes being considered
def TrySolve(S, i, j, A):
    while i < j and A > S[i]: #Can eat, so do so
        A += S[i]
        i += 1

    if i >= j: #Base case, all eaten
        return 0

    #Now it needs help. Try adding and removing
    helpByRemove = 1 + TrySolve(S, i, j-1, A)

    if A > 1: #If too small to eat even 1 then don't bother adding
        helpByAdd = 1 + TrySolve(S, i, j, A + (A-1))
        return min(helpByAdd, helpByRemove)
    else:
        return helpByRemove







import time
start = time.clock()

T = int(input.readline())
for i in range(1,T+1):
    solve(i)

print("{0} milliseconds".format((time.clock() - start) * 1000))
