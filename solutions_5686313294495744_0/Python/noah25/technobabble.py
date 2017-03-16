# Google Code Jam 2016 Round 1B
# Problem C. Technobabble

def reorder(pairs):
    first = []
    last = []
    new = []
    for pair in pairs:
        if pair[0] not in first and pair[1] not in last:
            first += [pair[0]]
            last += [pair[1]]
            new += [pair]
    for pair in pairs:
        if pair not in new:
            if pair[0] not in first or pair[1] not in last:
                if pair[0] not in first:
                    first += [pair[0]]
                    new += [pair]
                elif pair[1] not in last:
                    last += [pair[1]]
                    new += [pair]
    print pairs
    print new
    return len(pairs) - len(new)

def techno():
    f = open('commands.txt', 'r')
    g = open('techno.txt', 'w')
    line = 0
    part = 0
    for i in f:
        if line == 0:
            T = int(i)
            line = 1
        else:
            if part == 0:
                N = int(i)
                pairs = []
                part = 1
            else:
                first = ''
                last = ''
                spaces = 0
                for j in i[:-1]:
                    if j == ' ':
                        spaces = 1
                    else:
                        if spaces == 0:
                            first += j
                        else:
                            last += j
                pairs += [[first, last]]
                if len(pairs) == N:
                    g.write('Case #' + str(line) + ': ')
                    g.write(str(reorder(pairs)))
                    g.write((T != line)*'\n')
                    part = 0
                    line += 1
    f.close()
    g.close()
                        
            
