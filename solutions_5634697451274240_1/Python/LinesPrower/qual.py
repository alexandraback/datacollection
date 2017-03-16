import io, sys
import datetime, copy

fin = None

def inv(x):
    return ''.join('+' if c == '-' else '-' for c in x)

def solve():    
    s = sstrip()
    res = 0
    n = len(s)
    while True:
        k = 0
        while k < n and s[k] == '+':
            k += 1
        if k == n:
            return res
        if k > 0:
            s = '-' * k + s[k:]
            res += 1
        p = s.rfind('-')
        if p == -1:
            return res
        s = inv(reversed(s[:p+1])) + s[p+1:]
        res += 1
        
        
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