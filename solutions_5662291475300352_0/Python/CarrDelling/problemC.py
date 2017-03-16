
def solve(N, problem):

    if N == 1:
        return 0

    pos_A = int(problem[0][0])
    time_A = int(problem[0][2])

    pos_B = int(problem[1][0])
    time_B = int(problem[1][2])

    if pos_A > pos_B:

        pos_A , pos_B = pos_B , pos_A
        time_A , time_B = time_B , time_A

    if time_B < time_A:

        total_A = time_A * (float(360-pos_A)/360.0)
        total_B = (time_B * (float(360-pos_B)/360.0)) + time_B

        if total_B <= total_A:
            return 1
        else:
            return 0

    if time_B > time_A:

        total_B = time_B * (float(360-pos_B)/360.0)
        total_A = (time_A * (float(360-pos_A)/360.0)) + time_A

        if total_A <= total_B:
            return 1
        else:
            return 0

    return 0

if __name__ == '__main__':

    input = open('C-small-1-attempt1.in','r')
    output = open('solutionA.txt','w')

    nCases = int(input.readline())

    outList = []

    for case in range(0,nCases):

        N = int(input.readline())

        problem = []

        for i in range(0,N):

            pos,hikers,time = input.readline().split()

            problem.append((pos,hikers,time))

        solution = solve(N,problem)
        out ='Case #%d: %d' % ((case+1),solution)
        outList.append(out)

    output.write('\n'.join(outList))
    input.close()
    output.close()