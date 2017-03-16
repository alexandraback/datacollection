
def solve(C,D,V,denom):

    cost = 0
    targets = [0] * (V+1)

    for coin in denom:
        val = int(coin)
        new_targets = list(targets)

        new_targets[val] = 1
        for i in range(1,V+1):
            if targets[i] == 1 and i+val <= V:
                new_targets[i+val] = 1

        targets = list(new_targets)

    #print '*'+str(V)+'*'+','.join(denom)
    for ii in range(1,V+1):

        #print [str(a)+',' for a in targets]

        if targets[ii] == 0:

            #new coin: denom i
            #print ii
            val = ii
            cost += 1

            new_targets = list(targets)

            new_targets[val] = 1
            for i in range(1,V+1):
                if targets[i] == 1 and i+val <= V:
                    new_targets[i+val] = 1

            targets = list(new_targets)



    return cost

if __name__ == '__main__':

    input = open('C-small-attempt2.in','r')
    output = open('solutionC.txt','w')

    nCases = int(input.readline())

    outList = []

    for case in range(0,nCases):
    
        line = input.readline().strip()

        C,D,V = line.split(' ')
        denom = input.readline().strip().split(' ')

        solution = solve(int(C),int(D),int(V),denom)

        out ='Case #%d: %d' % ((case+1),solution)
        outList.append(out)

    output.write('\n'.join(outList))
    input.close()
    output.close()