'''
Created on May 22, 2011

@author: doronv
'''

# import section

def solve(inputFile, outputFile):
    # read case number
    T = int(inputFile.readline())
    
    # iterate on all cases
    for t in range(T):

        # read space separated values
        values = inputFile.readline().split()
        # read number of people
        N = int(values[0])

        # read just scores
        Jis = [int(values[i]) for i in xrange(1, N + 1)]

        X = sum(Jis)

        # reset arrays
        minsNeeded = [0 for i in xrange(N)]

        M = N;
        for i in xrange(N):
            if Jis[i] * N > 2 * X:
                Jis[i] = -1
                M -= 1

        for i in xrange(N):
            Ji = Jis[i]
            if not Ji == -1:
                sumOthers = 0
                for n in xrange(N):
                    if n == i or Jis[n] == -1:
                        continue
                    sumOthers += Jis[n]
                minNeeded =  float(sumOthers - (M - 1) * Ji + X) / (M * X)
                minsNeeded[i] = minNeeded * 100

        # output case result
        outputLine = 'Case #' + str(t + 1) + ': '
        for i in xrange(N):
            # Add results to output 
            outputLine += '%3.6f'%(minsNeeded[i]) + ' '

        # output results
        outputFile.write(outputLine + '\n')

    # close Input and output 
    inputFile.close()
    outputFile.close()