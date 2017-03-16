import sys
import string

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout

def min_score(R,C,W):
    n = C/W
    turn = R * n
    if C % W != 0: turn += 1
    turn += W-1
    return turn

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            R, C, W = map(int, f.readline().split(' '))
            outf.write('Case #{0}: {1}'.format(x+1, min_score(R,C,W)))
            outf.write('\n')
