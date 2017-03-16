
def solve(X,R,C):

    possible = True

    if X == 1:
        pass

    if X == 2:
        possible = ((R*C)%X == 0)

    if X == 3:
        if R < 2 or C < 2:
            possible = False
        else:
            possible = ((R*C)%X == 0)

    if X == 4:
        possible = ((R+C) > 6)

    return 'GABRIEL' if possible else 'RICHARD'

if __name__ == '__main__':

    input = open('D-small-attempt0.in','r')
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