import sys, math
import pprint

def count(q, start, end):
    return (start + 1) * (q - end)

def work(s, n):
    vowel='aeoiu'
    q = len(s)
    c = 0
    sum = 0
    t = []
    last = 0
    for i in range(q):
        if not s[i] in vowel:
            c = c + 1
        else:
            c = 0
        t.append(c)
        if c >= n:
            last = i - n + 2
        sum =  sum + last
            
    #print t
    return sum

if __name__=='__main__':
    fin = open('A-large.in')
    #fin = open('a1.in')
    fout = open('a.out','wt')
    #fout = sys.stdout
    line = fin.readline()
    t = int(line)
    for i in range(t):
        lines = fin.readline().strip().split()
        s = lines[0]
        n = int(lines[1])
        #print 's=%s,n=%d'%(s,n)
        fout.write('Case #%d: %s\n' %(i+1,work(s,n)))
    fout.close()
