import sys

args = sys.argv

if len(args) < 2:
    print 'small or large?'
    exit()

inp = args[1]

out = open(inp + '_OUT', 'w')

# No change before this

dict = {}

def load():
    mapping = open('mapping.txt')
    for line in mapping:
        arr = line.split()
        dict[arr[0]] = arr[1]
    dict[' '] = ' '

load()

N = int(raw_input())

for i in xrange(1, N+1):
    line = raw_input()
    result = ''
    for j in xrange(len(line)):
        result += dict.get(line[j])
    out.write('Case #' + str(i) + ': ' + result + '\n')

# No change after this

out.close()
