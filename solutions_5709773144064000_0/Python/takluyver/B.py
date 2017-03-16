problem = 'B-small-attempt0'

fin = open(problem + '.in')
fout = open(problem + '.out', 'w')

def read_ints():
    return [int(x) for x in fin.readline().strip().split()]

T = read_ints()[0]
for caseno in range(1, T+1):
    C, F, X = [float(x) for x in fin.readline().strip().split()]
    n = 0
    t = 0.0
    
    while (X/(2+F*n)) > (C/(2+F*n)) + (X/(2+F*(n+1))):
        t += C/(2+F*n)
        n += 1
    
    t += X/(2+F*n)
    
    
    fout.write("Case #%d: %.7f\n" % (caseno, t))