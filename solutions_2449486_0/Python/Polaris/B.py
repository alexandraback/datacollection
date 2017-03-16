problem = 'B'
scale = 'small'

infile = problem + '-' + scale + '.in'
outfile = problem + '-' + scale + '.out'

input = open(infile, 'r')
output = open(outfile, 'w')

ncase = int(input.readline().rstrip()) 

def process(input):
    lawn = []
    n, m = input.readline().rstrip().split(' ')
    n = int(n)
    m = int(m)
    for i in range(0, n):
        lawn.append([int(x) for x in input.readline().rstrip().split(' ')])
    
    for i in range(0, n):
        for j in range(0, m):
            v = lawn[i][j]
            vertical = True
            horizontal = True
            for j_left in range(0, j):
                if v < lawn[i][j_left]:
                    horizontal = False
                    break;
            for j_right in range(j+1, m):
                if v < lawn[i][j_right]:
                    horizontal = False
                    break;
            for i_up in range(0, i):
                if v < lawn[i_up][j]:
                    vertical = False
                    break;
            for i_down in range(i+1, n):
                if v < lawn[i_down][j]:
                    vertical = False
                    break;
            if not horizontal and not vertical:
                return "NO"
    return "YES"
        

for k in range(1, ncase+1):
    result = process(input)
    print(k, result)
    output.write("Case #%d: %s\n" % (k, result))

