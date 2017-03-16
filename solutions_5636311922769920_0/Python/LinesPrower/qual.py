import io, sys
import datetime, copy

fin = None


def solve():    
    k, c, s = nums()
    n = (k + c - 1) // c
    if n > s:
        return 'IMPOSSIBLE'
    
    def pows():
        x = 1
        while True:
            yield x
            x *= k
    
    curp = 0
    res = []
    for _ in range(n):
        v = [(curp + j) % k for j in range(c)]
        curp += c
        pos = sum(a * b for a, b in zip(v, pows()))
        res.append(str(pos + 1))
    return ' '.join(res)        
        
    
        
        
def main():
    fname = 'a.in'
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    global fin    
    fin = io.open(fname)
    fout = io.open(fname + '.out', 'w')
    t0 = datetime.datetime.now()    
    t = int(fin.readline())
    
    for i in range(t):
        fout.write('Case #%d: ' % (i + 1))
        fout.write('%s\n' % str(solve()))
    
    print('Time = %s' % str(datetime.datetime.now() - t0))
    fin.close()
    fout.close()

def nums():
    return [int(x) for x in fin.readline().split()]
def fnums():
    return [float(x) for x in fin.readline().split()]
def num():
    return int(fin.readline())
def sstrip():
    return fin.readline().strip()
def strs():
    return fin.readline().split()
def arrstr(a, sep = ' '):
    return sep.join([str(x) for x in a])

if __name__ == '__main__':
    main()
    #print(solvex(1, 9, 6))
    #solveb_meta()