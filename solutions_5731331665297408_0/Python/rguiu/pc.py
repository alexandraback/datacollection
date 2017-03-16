problem = "C"
case = "small" # "small" "large"

input_file  = "%s-%s.in" % (problem,case)
output_file = "%s-%s.out" % (problem,case)

def visit(ocurrent, sequence, paths, codesleft):
    print codesleft
    if (len(codesleft)==0):
        return [ocurrent]
    for n,a in enumerate(codesleft):
        sequen = list(sequence)
        sequen.append(ocurrent)
        while(len(sequen)>0):
            current = sequen[-1]
            if (paths[current[1]][a[1]]):
                codesnew = list(codesleft)
                codesnew.pop(n)
                m = visit(a, sequen,paths, codesnew)
                if (m != None):
                    print "****", m
                    al = [ocurrent]
                    al.extend(m)
                    return al
            sequen.pop(-1)
    return None

with open(input_file, 'r') as inputf, open(output_file, 'w') as outputf:
    lines = inputf.readlines()
    N = int(lines.pop(0))
    for i in range(0,N,1):
        # do something
        N,M  = map(int,lines.pop(0).strip().strip().split(' '))
        codes = []
        paths = [None] * N
        for a in range(N):
            codes.append((lines.pop(0).strip(),a))
            paths[a] = [False] * N
        for b in range(M):
            x,y = map(int, lines.pop(0).strip().split(' '))
            print x,y,N
            paths[x-1][y-1] = True
            paths[y-1][x-1] = True
        codes.sort(key=lambda x: x[0])

        for u, c in enumerate(codes):
            ocodes = list(codes)
            ocodes.pop(u)
            h = visit(c,[c],paths,ocodes)
            print "---", h
            if (h != None):
                b = ""
                for hhh in h:
                    b = b + hhh[0]
                outputf.write("Case #%s: %s\n" % (i+1, b))
                break
