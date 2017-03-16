import sys

filetext = ''

def fetch(target):
    s = '%d: ' % target
    start = filetext.find(s)
    end = filetext.find('\n', start)
    return int(filetext[start+len(s) : end])
         
if __name__ == '__main__':
    with open('numdists.txt', 'r') as f:
        filetext = f.read()
    ncases = int(sys.stdin.readline())
    for cs in range(1, ncases+1):
        num = int(sys.stdin.readline())
        dist = fetch(num)
        print 'Case #%d: %d' % (cs, dist)

