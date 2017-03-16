'''
Created on 09.04.2016

@author: dw
'''
import sys



def read_input(filename):
    lines = open(filename).readlines()[1:]
    return [tuple(map(int, line.split())) for line in lines]
        

def process_case(inp):
    K, C, S = inp
    assert(K == S)
    d = sum(K**n for n in range(C))
    zs = [i * d + 1 for i in range(K)]
    return ' '.join(str(z) for z in zs)

def process_case2(inp):
    K, C, S = inp
    assert(K == S)
    def pos(i, l):
        if l == 1:
            return i
        return (K ** (l-1)) * (i-1) + pos(i, l-1) 
    return ' '.join(str(pos(i, C)) for i in range(1, K+1))

if __name__ == '__main__':
    infile = sys.argv[1]
    outfile = (infile[:-3] if infile.endswith('.in') else infile) + '.out'
    with open(outfile, 'w') as f_out:
        for i, inp in enumerate(read_input(infile)):
            line = 'Case #%d: %s' % (i+1, process_case(inp)) 
            print(line)
            f_out.write(line + '\n')