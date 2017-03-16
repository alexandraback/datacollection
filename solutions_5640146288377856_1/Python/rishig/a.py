import sys

def run(line):
    r,c,w = [int(x) for x in line.split()]
    ans = r * (c//w) + w
    if c % w == 0:
        ans -= 1
    return ans

fin = open(sys.argv[1])
T = int(fin.readline().strip())
for i in range(1,T+1):
    line = fin.readline().strip()
    ans = run(line)
    print('Case #%d: %s' % (i, ans))
