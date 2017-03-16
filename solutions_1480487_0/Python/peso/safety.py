import sys
import string

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout

def find_target(s,total):
    i = 1
    target = (sum(s[0:i])+total) / i
    while i<len(s) and target > s[i]:
        i = i + 1
        target = (sum(s[0:i])+total) / i
    return target

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            P = map(float, f.readline().split(' '))
            N = P[0] # contestants
            j = P[1:] # point values from judges
            t = sum(j)
            s = j[:]
            s.sort()
            target = find_target(s,t)
            frac = []
            for q in j:
                want = (target - q) / t
                if want < 0:
                    want = 0.0
                frac.append(want * 100)
            outf.write('Case #{0}: '.format(x+1))
            outf.write(' '.join(map(str,frac)))
            outf.write('\n')
