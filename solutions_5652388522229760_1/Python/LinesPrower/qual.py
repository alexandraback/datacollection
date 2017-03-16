import io, sys
import datetime, copy

fin = None


def solve():    
    n = num()
    if n == 0:
        return 'INSOMNIA'
    digs = set()
    t = n
    while True:
        q = t
        while q:
            digs.add(q % 10)
            q //= 10
        if len(digs) >= 10:
            break
        t += n
    return t        
        
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