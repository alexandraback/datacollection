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
            N = P[0] #startnum
            seen = {}
            left = 10
            if N != 0:
                last = 0
                while left > 0:
                    last += N
                    for c in str(last):
                        if c not in seen:
                            seen[c] = 1
                            left -= 1
            outf.write('Case #{0}: '.format(x+1))
            if N == 0:
                outf.write('INSOMNIA')
            else:
                outf.write(str(last))
            outf.write('\n')
