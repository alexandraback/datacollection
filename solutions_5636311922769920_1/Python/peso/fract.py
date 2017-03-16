import sys
import string

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            P = map(int, f.readline().split(' '))
            K = P[0] # original tiles
            C = P[1] # complexity
            S = P[2] # students (tests)
            result = 'IMPOSSIBLE'
            if S*C >= K:
                ts = []
                i = 0
                for s in range(0,(K-1)/C+1):
                    j = 0
                    for c in range(0,C):
                        # test one tile
                        j = j*K
                        if i<K:
                            j += i
                            i += 1
                    ts.append(j)
                result = " ".join(str(x+1) for x in ts)
            outf.write('Case #{0}: '.format(x+1))
            outf.write(result)
            outf.write('\n')
