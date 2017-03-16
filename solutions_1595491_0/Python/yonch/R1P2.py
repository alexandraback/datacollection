'''
Created on Apr 13, 2012

@author: yonch
'''


def eat(lines):
    return lines[0], lines[1:]
 
def do(l):
    l = map(int,l.split(' '))
    N, S, p = l[:3]
    l = l[3:]
    
    l = filter(lambda x: x>=p + 2*max(0, p-2), l)
    k = len(filter(lambda x: x>=p+2*max(0,p-1), l))
    return str(k + min(len(l) - k, S))

def read():
    return """4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21""".splitlines()

def readf():
    INPUT_FILENAME = '/home/yonch/Downloads/B-small-attempt0.in'
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
    
    file('/home/yonch/Downloads/Solution.out','w').write(outfile)