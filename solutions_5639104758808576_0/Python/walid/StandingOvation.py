__author__ = 'walid'

filename = 'A-small'

inFile = open('/Users/walid/Downloads/'+filename, 'r')
outFile = open('/Users/walid/Downloads/'+filename+'out', 'w')

Testcases = (int)(inFile.readline())

def process(audience, it):
    print(audience)
    friends = 0
    standing = 0
    for i in range(len(audience)):
        if(i > standing):
            friends += i-standing
            standing = i
        standing += audience[i]
    outFile.write('Case #{}: {}\n'.format(it, friends))

it = 0
for line in inFile:
    elems = line.split(' ')
    audience = [(int)(a) for a in elems[1].strip()]
    process(audience, it)
    it += 1
