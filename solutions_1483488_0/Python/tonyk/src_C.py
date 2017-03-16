fn = 'C-small-attempt0'
#fn = 'C-small-attempt1'
#fn = 'sample'

inp = open(fn + '.in', 'r')
out = open(fn + '.out', 'w')

n = int(inp.readline())
for i in range(n):
    line = inp.readline()
    spl = line.split()

    a = int(spl[0])
    b = int(spl[1])

    l = len(str(a)) - 1
    pot = 1
    for j in range(l):
        pot *= 10
        
    sol = 0
    for j in range(a, b+1):
        tmp = j
        mem = []
        for k in range(l):
            p1 = tmp % 10
            p2 = tmp / 10
            tmp = p1*pot + p2
            if tmp >= a and tmp <= b and tmp > j:
                if not tmp in mem:
                    sol += 1
                    mem.append(tmp)
            
        
    out.writelines('Case #' + str(i+1) + ': ' + str(sol) + '\n')

inp.close()
out.close()
