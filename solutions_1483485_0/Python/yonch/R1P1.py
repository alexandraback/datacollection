'''
Created on Apr 13, 2012

@author: yonch
'''

d = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

def eat(lines):
    return lines[0], lines[1:]
 
def do(l):
    return ''.join(map(lambda x: d[x], l))

def read():
    return """3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv""".splitlines()

def readf():
    INPUT_FILENAME = '/home/yonch/Downloads/A-small-attempt0.in'
    return file(INPUT_FILENAME).read().splitlines()

if __name__ == '__main__':
    lines = readf()
    l, lines = eat(lines)
    N = int(l)
    outfile = ""
    for i in xrange(N):
        l, lines = eat(lines)
        outline = "Case #%d: %s" % (i+1, do(l))
        print outline
        outfile += outline + "\n"
    
    file('/home/yonch/Downloads/Solution.out','w').write(outfile)