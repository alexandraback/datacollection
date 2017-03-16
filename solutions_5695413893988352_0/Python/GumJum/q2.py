
import sys

def getPerm(c):
    lc = [c]    
    while '?' in lc[0]:
        i = lc[0].index('?')
        newlc = []
        for a in lc:
            newlc += [a[:i] + x + a[i+1:] for x in '0123456789']
        lc = newlc
    return lc

def brute(c,j):
    lc = getPerm(c)
    lj = getPerm(j)
    l = []
            
    for x in lc:
        for y in lj:
            l.append((x,y,abs(int(x) - int(y))))
    
    mina = (0,0,2**20)
    for a in l:
        if a[2] < mina[2]:
            mina = a
    return mina
        
def solve(c,j):
    b = brute(c,j)
    return b[0] + ' ' + b[1]
    

def main():
    to_write = ''
    with open(sys.argv[1], 'r') as f:
        first_line = f.readline()
        count = 0
        
        for l in f:
            count += 1
            args = l.strip().split(' ')
            s = solve(args[0], args[1])
            to_write += 'Case #' + str(count) + ': ' + s + '\n'
    
    with open(sys.argv[2], 'w') as f:
        f.write(to_write)
        
if __name__ == '__main__':
    #print checkAllDivs('111111')
    #print checkAllDivs()
    #print getTest(15, 60)
    main()