#fn = 'B-small-attempt0'
#fn = 'B-small-attempt1'
#fn = 'B-small-attempt2'
fn = 'B-small-attempt3'
#fn = 'sample'

inp = open(fn + '.in', 'r')
out = open(fn + '.out', 'w')

n = int(inp.readline())
for i in range(n):
    line = inp.readline()
    spl = line.split()

    n = int(spl[0])
    s = int(spl[1])
    p = int(spl[2])

    if p > 1:
        mg = 3*p - 5
        vg = 3*(p - 1)

        ve = 0
        sr = 0

    if p == 0:
        sol = n
    else:
        sol = 0
        for j in range(n):
            t = int(spl[j+3])
            if p == 1:
                if t > 0:
                    sol += 1
            else:
                if t > vg:
                    ve += 1
                elif t > mg:
                    sr += 1
        if p > 1:
            sol = ve
            if s < sr:
                sol += s
            else:
                sol += sr

    out.writelines('Case #' + str(i+1) + ': ' + str(sol) + '\n')

inp.close()
out.close()
