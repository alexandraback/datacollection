'''
Created on 09.04.2016

@author: dw
'''
import sys



def read_input(filename):
    lines = open(filename).readlines()[1:]
    return [tuple(map(int, line.split())) for line in lines]

def pos(K, js):
    """Return position when going down ks indices"""
    p = js[0] % K or K
    for j in js[1:]:
        j = j % K or K
        p = K * (p - 1) + j
    return p

def expandall(tile, C):
    GS = 'G' * len(tile)
    def expand(xs):
        return ''.join(tile if x == 'L' else GS for x in xs)
    def _expandall(xs, limit):
        if limit == 1:
            return xs
        else:
            return _expandall(expand(xs), limit-1)
    
    return _expandall(tile, C)

def onegs(K):
    return ['L' * i + 'G' + 'L' * (K - i - 1) for i in range(K)]

def process_case(inp):
    K, C, S = inp
    if K - C >= S:
        return 'IMPOSSIBLE'
    if K <= C:
        # exponegs = '\n'.join(expandall(tile, C) for tile in onegs(K))
        return str(pos(K, list(range(1, C+1)))) # + "\n" + exponegs 
    else:
        N = (K - 1) // C + 1 
        js = list(range(1, C * N + 1))
        ps = [pos(K, js[C*i:C*(i+1)]) for i in range(N)]
        #exponegs = '\n'.join(expandall(tile, C) for tile in onegs(K))
        return ' '.join(map(str, ps)) # + '\n' + exponegs
    
if __name__ == '__main__':
    infile = sys.argv[1]
    outfile = (infile[:-3] if infile.endswith('.in') else infile) + '.out'
    with open(outfile, 'w') as f_out:
        for i, inp in enumerate(read_input(infile)):
            line = 'Case #%d: %s' % (i+1, process_case(inp)) 
            print(line)
            f_out.write(line + '\n')
            