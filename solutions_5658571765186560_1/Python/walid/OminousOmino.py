__author__ = 'walid'

filename = 'D-large'
# dirname = '/Users/walid/Downloads/'
dirname = 'D:\\Downloads\\'
inFile = open(dirname+filename+'.in', 'r')
outFile = open(dirname+filename+'.out', 'w')

Testcases = (int)(inFile.readline())

def process(X, R, C, it):
    m = min(R, C)
    M = max(R, C)
    print(X, m, M)
    minX = 7
    if(m == 1):
        minX = 3
    if(m == 2 and M <= 8):
        minX = 5
    if(m == 2 and M <= 4):
        minX = 4
    if(m == 3 and M <= 3):
        minX = 5

    print(minX)
    if((m*M) % X > 0 or X >= minX or X > M):
        r = 'Richard'
    else:
        r = 'Gabriel'
    print(r)
    outFile.write('Case #{}: {}\n'.format(it, r))

it = 1
for line in inFile:
    elems = line.split(' ')
    [X, R, C] = [(int)(a.strip()) for a in elems]
    process(X, R, C, it)
    it += 1
