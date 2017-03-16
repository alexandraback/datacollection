from sys import stdin, stdout


def solve(C, V, denoms):

    # assume C = 1
    newDenoms = 0

    if 1 not in denoms:
        newDenoms += 1
    else:
        denoms.remove(1)

    scope = 1  #( * C )

    if denoms:
        d = denoms.pop(0)
    else:
        d = 1E12

    while True:
        #print scope, newDenoms, d

        if scope >= V:
            return newDenoms

        if scope >= (d - 1):
            scope += d

            if denoms:
                d = denoms.pop(0)
            else:
                d = 1E12

        else:
            # add new denom of scope + 1
            scope += scope + 1
            newDenoms += 1


if __name__ == '__main__':

    T = int(stdin.readline())

    for i in range(T):
        # read input for this problem

        C, _, V = map(int, stdin.readline().strip().split())
        denoms = map(int, stdin.readline().strip().split())

        if C == 1:
            result = solve(C, V, denoms)
            
            print "Case #%d: %s"%(i+1, result)