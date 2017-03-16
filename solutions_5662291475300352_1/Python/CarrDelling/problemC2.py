
def time_finish(time,pos):
    return float(time) * (float(360-float(pos))/360.0)


def solve(N, problem):

    if N == 1:
        return 0

    faster = 0
    fast_time = time_finish(problem[0][2],problem[0][0]) + float(problem[0][2])

    for i in range(1,len(problem)):
        loop_time = time_finish(problem[i][2],problem[i][0]) + float(problem[i][2])

        if loop_time < fast_time:
            fast_time = loop_time
            faster = i

    cost = 0

    for i in range(0,len(problem)):

        short_time = time_finish(problem[i][2],problem[i][0])

        if short_time >= fast_time:
            cost += int(problem[i][1])

    return cost

if __name__ == '__main__':

    input = open('C-small-2-attempt1.in','r')
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