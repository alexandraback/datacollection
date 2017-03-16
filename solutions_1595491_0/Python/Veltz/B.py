# import section

def solve(inputFile, outputFile):
    # read case number
    T = int(inputFile.readline())
    
    # iterate on all cases
    for t in xrange(T):
        # get L, d, N and C (I call t, d to avoid name conflicts)
        values = inputFile.readline().split(' ')
        N = int(values[0])
        S = int(values[1])
        p = int(values[2])

        # get Tjs
        Tjs = [(int(values[3 + c])) for c in xrange(N)]

        listTjs = list(Tjs)
        listTjs.sort(None, None, True)

        # accumulate successfulGooglers
        successfulGooglers = 0
        for j in listTjs:
            if ( j >= 3 * p - 2 ):
                # no need for an irregular result
                successfulGooglers = successfulGooglers + 1
            elif (( j >= 3 * p - 4 ) and (S > 0) and (p > 1)):
                successfulGooglers = successfulGooglers + 1
                S = S - 1;
            else:
                break;

        # output case result
        OutputLine = 'Case #' + str(t + 1) + ': ' + str(successfulGooglers) +'\n'
        outputFile.write(OutputLine)