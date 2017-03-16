problem = 'A'
scale = 'large'

infile = problem + '-' + scale + '.in'
outfile = problem + '-' + scale + '.out'

input = open(infile, 'r')
output = open(outfile, 'w')

n = int(input.readline().rstrip()) 


def process(input):
    has_dot = False
    matrix = []
    for i in range(0, 4):
        matrix.append(input.readline().rstrip())
    input.readline().rstrip()
    
    for i in range(0, 4):
        candidate = None
        for j in range(0, 4):
            v = matrix[i][j]
            if v == 'X' or v == 'O':
                if candidate == None:
                    candidate = v
                elif candidate != v:
                    break
                else:
                    pass
            elif v == 'T':
                pass
            else:
                has_dot = True
                break
        else:
            return candidate + ' won'
        
    for i in range(0, 4):
        candidate = None
        for j in range(0, 4):
            v = matrix[j][i]
            if v == 'X' or v == 'O':
                if candidate == None:
                    candidate = v
                elif candidate != v:
                    break
                else:
                    pass
            elif v == 'T':
                pass
            else:
                has_dot = True
                break
        else:
            return candidate + ' won'
                
    for i in range(0, 1):
        candidate = None
        for j in range(0, 4):
            v = matrix[j][j]
            if v == 'X' or v == 'O':
                if candidate == None:
                    candidate = v
                elif candidate != v:
                    break
                else:
                    pass
            elif v == 'T':
                pass
            else:
                has_dot = True
                break
        else:
            return candidate + ' won'

    for i in range(0, 1):
        candidate = None
        for j in range(0, 4):
            v = matrix[j][3-j]
            if v == 'X' or v == 'O':
                if candidate == None:
                    candidate = v
                elif candidate != v:
                    break
                else:
                    pass
            elif v == 'T':
                pass
            else:
                has_dot = True
                break
        else:
            return candidate + ' won'

    if has_dot:
        return "Game has not completed"
    else:
        return "Draw"

for k in range(1, n+1):
    result = process(input)
    print(k, result)
    output.write("Case #%d: %s\n" % (k, result))

