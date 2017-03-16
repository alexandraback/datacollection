import sys
import itertools

def findsubsets(S,m):
    return set(itertools.combinations(S, m))

def lst(S):
    res = ''
    #print S
    for x in S:
        res += str(x)+' '
    return res

def solve(N, testcase):
    S = set(testcase)
    subset = {}

    for i in S:
        subset[i] = set([i])

    for k in xrange(2,N):
        sets = findsubsets(S,k)

        for ss in sets:
            if sum(ss) in subset:
                return '\n'+lst(subset[sum(ss)])+'\n'+lst(set(ss))
            else:
                subset[sum(ss)] = set(ss)
    
    return '\nImpossible'

def main(input_file, out_file):
    f = open(input_file, 'r')
    g = open(out_file, 'w')
    T = int(f.readline())
    
    
    for i in range(T):
        testcase = f.readline().split()
        N = int(testcase[0])
        testcase = map(int,testcase[1:])
        
        sol = solve(N, testcase)
        print 'Case #{0}: {1}'.format(i+1, sol)
        g.write('Case #{0}: {1}\n'.format(i+1, sol))
    f.close()
    g.close()

if __name__ == "__main__":
    main('input1.txt', 'output.txt')
        
    
