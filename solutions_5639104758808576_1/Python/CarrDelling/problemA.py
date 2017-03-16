
def solve(shyness, levels):

    current = 0
    required = 0
    additional = 0

    for l in levels:

        total = current + additional

        if total < required:
            additional += required - total

        current += int(l)
        required+= 1

    return additional

if __name__ == '__main__':

    input = open('A-large.in','r')
    output = open('solutionA.txt','w')

    nCases = int(input.readline())

    outList = []

    for case in range(0,nCases):

        problem = input.readline()

        parts = problem.strip().split(' ')

        if len(parts) != 2:
            continue

        shyness = int(parts[0])
        levels = parts[1]

        solution = solve(shyness, levels)

        out ='Case #%d: %d' % ((case+1),solution)
        outList.append(out)

    output.write('\n'.join(outList))
    input.close()
    output.close()