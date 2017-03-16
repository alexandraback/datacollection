filename = 'B-small-attempt0'
inputfile = filename + '.in'
outputfile = filename + '.out'

resulttemplate = "Case #{t}: {res}\n"

with open(inputfile) as input, open(outputfile, 'w') as output:
    T = int(input.readline())
    for t in xrange(T):
        A, B, K = map(int, input.readline().split())
        res = 0
        for a in xrange(A):
            for b in xrange(B):
                if a & b < K:
                    res += 1
        output.write(resulttemplate.format(t=t+1, res=res))
        print res