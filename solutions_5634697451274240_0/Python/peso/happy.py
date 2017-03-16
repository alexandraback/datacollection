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
            P = f.readline().strip() + '+'
            flips = 0
            for i in range(0,len(P)-1):
                if P[i] != P[i+1]:
                    flips += 1
            outf.write('Case #{0}: {1}'.format(x+1,flips))
            outf.write('\n')
