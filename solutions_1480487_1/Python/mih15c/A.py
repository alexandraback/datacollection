import sys

def solve(N, testcase):
    X = sum(testcase)
    percentages = ''
    p = []
    sneg = {}
    
    max_val = (2.0 * X) / N
    if max_val >= max(testcase):
        for i in xrange(N):
            min_percentage = (max_val - testcase[i])/X * 100.0
            percentages += str(min_percentage) + ' '
    else:
        
        imax = testcase.index(max(testcase))
        #max_val = (2.0 * X) / (N-1)
        for i in xrange(N):
            min_percentage = (max_val - testcase[i])/X * 100.0
            if min_percentage < 0.0:
                sneg[i] = min_percentage
                p.append(0.0)
            else:
                p.append(min_percentage)

        negs = len(sneg)
        if negs != 0:
            for index in sneg:
                for i in xrange(N):
                    if p[i] > 0.0:
                        p[i] += sneg[index] / (N-negs)

        for t in p:
            percentages += str(t)+' '
            
        
    return percentages
    


def main(input_file, out_file):
    f = open(input_file, 'r')
    g = open(out_file, 'w')
    T = int(f.readline())
    
    for i in range(T):
        testcase = f.readline().split()
        N = int(testcase[0])
        testcase = map(int,testcase[1:])
        
        sol = solve(N, testcase)
        print 'Case #{0}: {1} | {2}'.format(i+1, sol, testcase)
        g.write('Case #{0}: {1}\n'.format(i+1, sol))
    f.close()
    g.close()

if __name__ == "__main__":
    main('input.txt', 'output.txt')
        
    
