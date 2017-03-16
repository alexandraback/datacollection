
fn = 'A-large'
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
        #each time we help, it will increase by 2*A-1. SO see how much we need to make it able to eat the next mote
        helpRequiredToEatNext = 0
        newA = A
        while newA <= S[i]:
            newA = 2*newA - 1
            helpRequiredToEatNext += 1

        if helpRequiredToEatNext < (j - i): #Don't bother helping it grow if it's faster to remove
            helpByAdd = helpRequiredToEatNext + TrySolve(S, i, j, newA)
            return min(helpByAdd, helpByRemove)

    return helpByRemove







import time
start = time.clock()

T = int(input.readline())
for i in range(1,T+1):
    solve(i)

print("{0} milliseconds".format((time.clock() - start) * 1000))
