'''
Created on Apr 13, 2012

@author: yonch
'''


def eat(lines):
    return lines[0], lines[1:]
 
def do(l):
    l = map(int,l.split(' '))
    A, B = l
    
    res = 0
    for n in xrange(A,B+1):
        s = set()
        nstr = str(n)
        for i in xrange(1, len(nstr)):
            m = int(nstr[i:] + nstr[:i])
            if m <= B and m > n:
                s.add(m)
        res += len(s)
    return res 

def read():
    return """4
1 9
10 40
100 500
1111 2222""".splitlines()

def readf():
    INPUT_FILENAME = '/home/yonch/Downloads/C-large.in'
    return file(INPUT_FILENAME).read().splitlines()

if __name__ == '__main__':
    lines = readf()
    line, lines = eat(lines)
    N = int(line)
    outfile = ""
    for i in xrange(N):
        line, lines = eat(lines)
        outline = "Case #%d: %s" % (i+1, do(line))
        print outline
        outfile += outline + "\n"
    
    file('/home/yonch/workspace/codejam/Solution.out','w').write(outfile)