import sys
#import pprint
def work(a,b):
    d = [1,4,9,121,484]
    i = 0
    p = range(a,b+1)
    count = 0
    for i in range(len(d)):
        if d[i] in p:
            count = count+ 1
    return count

if __name__=='__main__':
    fin = open('C-small-attempt0.in')
    #fin = sys.stdin
    fout = open('c.out','wt')
    line = fin.readline()
    t = int(line)
    for i in range(t):
        (a,b) = fin.readline().strip().split()
        a = int(a)
        b = int(b)
        fout.write('Case #%d: %s\n' %(i+1,work(a,b)))
    fout.close()
