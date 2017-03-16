
from math import sqrt

def solve_step(status,max_cost,overcost,current_best):

    high = len(status)

    if high < 4:
        return high+overcost

    current_best = min(high+overcost,current_best)

    root = int(sqrt(high))

    for i in range(2,root+1):

        old = high

        part_1 = high / i
        part_2 = high - part_1

        status[part_1-1] += 1
        status[part_2-1] += 1
        status[high-1] -= 1

        new_overcost = overcost + 1

        while status[high-1] < 1:
            high -= 1

        new_status = status[:high]

        step_cost = solve_step(new_status,high,new_overcost,current_best)

        #step_cost = 10000

        if step_cost < current_best:
            current_best = step_cost

        #return to previous situation
        status[part_1-1] -= 1
        status[part_2-1] -= 1
        status[old-1] += 1
        high = old

    return current_best

def solve(D, problem):

    parts = problem.split(' ')
    max_cost = int(max(parts))

    status = [0] * max_cost

    for i in parts:
        status[int(i)-1] += 1

    solution = solve_step(list(status),max_cost,0,max_cost)

    output = min(solution,max_cost)

    return output

if __name__ == '__main__':

    input = open('B-small-attempt1.in','r')
    output = open('solutionB.txt','w')

    nCases = int(input.readline())

    outList = []

    for case in range(0,nCases):

        D = int(input.readline())
        problem = input.readline().strip()

        solution = solve(D,problem)

        out ='Case #%d: %s' % ((case+1),solution)
        outList.append(out)

    output.write('\n'.join(outList))
    input.close()
    output.close()
