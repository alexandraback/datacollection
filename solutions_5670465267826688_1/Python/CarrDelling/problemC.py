


translator = {}
translator['Z'] = {}
translator['z'] = {}

translator['Z']['Z'] = 'Z'
translator['Z']['i'] = 'i'
translator['Z']['j'] = 'j'
translator['Z']['k'] = 'k'
translator['Z']['z'] = 'z'
translator['Z']['I'] = 'I'
translator['Z']['J'] = 'J'
translator['Z']['K'] = 'K'
translator['z']['Z'] = 'z'
translator['z']['i'] = 'I'
translator['z']['j'] = 'J'
translator['z']['k'] = 'K'
translator['z']['z'] = 'Z'
translator['z']['I'] = 'i'
translator['z']['J'] = 'j'
translator['z']['K'] = 'k'

translator['i'] = {}
translator['I'] = {}

translator['i']['Z'] = 'i'
translator['i']['i'] = 'z'
translator['i']['j'] = 'k'
translator['i']['k'] = 'J'
translator['i']['z'] = 'I'
translator['i']['I'] = 'Z'
translator['i']['J'] = 'K'
translator['i']['K'] = 'j'
translator['I']['Z'] = 'I'
translator['I']['i'] = 'Z'
translator['I']['j'] = 'K'
translator['I']['k'] = 'j'
translator['I']['z'] = 'i'
translator['I']['I'] = 'z'
translator['I']['J'] = 'k'
translator['I']['K'] = 'J'

translator['j'] = {}
translator['J'] = {}

translator['j']['Z'] = 'j'
translator['j']['i'] = 'K'
translator['j']['j'] = 'z'
translator['j']['k'] = 'i'
translator['j']['z'] = 'J'
translator['j']['I'] = 'k'
translator['j']['J'] = 'Z'
translator['j']['K'] = 'I'
translator['J']['Z'] = 'J'
translator['J']['i'] = 'k'
translator['J']['j'] = 'Z'
translator['J']['k'] = 'I'
translator['J']['z'] = 'j'
translator['J']['I'] = 'K'
translator['J']['J'] = 'z'
translator['J']['K'] = 'i'

translator['k'] = {}
translator['K'] = {}

translator['k']['Z'] = 'k'
translator['k']['i'] = 'j'
translator['k']['j'] = 'I'
translator['k']['k'] = 'z'
translator['k']['z'] = 'K'
translator['k']['I'] = 'J'
translator['k']['J'] = 'i'
translator['k']['K'] = 'Z'
translator['K']['Z'] = 'K'
translator['K']['i'] = 'J'
translator['K']['j'] = 'i'
translator['K']['k'] = 'Z'
translator['K']['z'] = 'k'
translator['K']['I'] = 'j'
translator['K']['J'] = 'I'
translator['K']['K'] = 'z'

def reduce(problem):

    while len(problem)>1:
        problem = translator[problem[0]][problem[1]] + problem[2:]

    return problem

def solve(L, X, problem):

    X_init = X

    #unsolvable with only one symbol
    if len(problem) < 2:
        return 'NO'

    #find if a 'i' is possible
    if X < 1:
        return 'NO'

    left = problem
    X -=1

    while left[0] != 'i':

        #expand if necessary
        if len(left) < 2:
            if X < 1:
                return 'NO'
            else:
                left = left + problem
                X -=1

                if (X_init - X) > 20:
                    return 'NO'

        left = translator[left[0]][left[1]] + left[2:]

    #update left
    left = left[1:]

    #cool! let's do the same for the 'k'
    if X < 1:
        right = left
        left = ''
    else:
        right = problem

    X -=1

    while right[-1] != 'k':

        #expand if necessary
        if len(right) < 2:
            if X < 0:
                return 'NO'
            else:
                if X == 0:
                    if len(left) < 1:
                        return 'NO'
                    right = left + right
                    X -=1
                    left = ''

                else:
                    right = problem + right
                    X -=1

                if (X_init - X) > 40:
                    return 'NO'

        right = right[:-2] + translator[right[-2]][right[-1]]

    #update right
    right = right[:-1]

    #reduce problem

    if X > 0:
        new_problem = reduce(problem)

        #consolidate problem
        X_a = X % 4

        if X_a == 0:
            new_problem = 'Z'
        if X_a == 1:
            new_problem = new_problem
        if X_a == 2:
            new_problem = new_problem + new_problem
        if X_a == 3:
            new_problem = new_problem + new_problem + new_problem

        center = left + new_problem + right
    else:
        if X == 0:
            center = left + right
        else:
            center = right

    # try to find 'j' in center
    if len(center) < 1:
        return 'NO'

    center = reduce(center)

    return 'YES' if center == 'j' else 'NO'

if __name__ == '__main__':

    input = open('C-large.in','r')
    output = open('solutionC.txt','w')

    nCases = int(input.readline())

    outList = []

    for case in range(0,nCases):
        print case
        parameters = input.readline()

        parts = parameters.strip().split(' ')

        if len(parts) != 2:
            continue

        L = int(parts[0])
        X = int(parts[1])

        problem = input.readline().strip()

        solution = solve(L,X,problem)

        out ='Case #%d: %s' % ((case+1),solution)
        outList.append(out)

    output.write('\n'.join(outList))
    input.close()
    output.close()
