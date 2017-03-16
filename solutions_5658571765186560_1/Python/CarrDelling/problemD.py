
def solve(X,R,C):

    possible = True

    if R < C:
        aux = R
        R = C
        C = aux

    if X < 3:
        if ((R*C)%X != 0):
            possible = False

    if X > 2 and X <= 6:

        if R < X or C < X-1 or ((R*C)%X != 0):
            possible = False

    if X > 6:
        possible = False

    return 'GABRIEL' if possible else 'RICHARD'

if __name__ == '__main__':

    input = open('D-large.in','r')
    output = open('solutionD.txt','w')

    nCases = int(input.readline())

    outList = []

    for case in range(0,nCases):

        problem = input.readline()

        parts = problem.strip().split(' ')

        if len(parts) != 3:
            continue

        X = int(parts[0])
        R = int(parts[1])
        C = int(parts[2])

        solution = solve(X, R, C)

        out ='Case #%d: %s' % ((case+1),solution)
        outList.append(out)

    output.write('\n'.join(outList))
    input.close()
    output.close()