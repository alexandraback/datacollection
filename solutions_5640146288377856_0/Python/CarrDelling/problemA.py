
def solve(R,C,W):

    cost = 0

    windows = C/W
    cost += windows

    rest = C % W

    if rest == 0:
        cost += W-1
    else:
        cost += W

    if R > 1:
        cost += (R-1)* windows

    return cost

if __name__ == '__main__':

    input = open('A-small-attempt2.in','r')
    output = open('solutionA.txt','w')

    nCases = int(input.readline())

    outList = []

    for case in range(0,nCases):

        line = input.readline().strip()
        R,C,W = line.split(' ')
        solution = solve(int(R),int(C),int(W))

        out ='Case #%d: %d' % ((case+1),solution)
        outList.append(out)

    output.write('\n'.join(outList))
    input.close()
    output.close()