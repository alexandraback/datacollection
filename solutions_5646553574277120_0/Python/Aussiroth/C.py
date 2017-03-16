infile = open("Csmall.txt", "r")
outfile = open("Csmallout.txt", "w")

def solve(value, currc, ptr):
    if ptr>=len(currc):
        return value
    if value-currc[ptr]==0:
        return 0
    else:
        if value-currc[ptr]>0:
            return min(solve(value-currc[ptr], currc, ptr+1), solve(value, currc, ptr+1))
        else:
            return value
        
tcase = int(infile.readline().rstrip())
for z in range(1, tcase+1):
    raw = infile.readline().rstrip().split()
    c, d, maxv = int(raw[0]), int(raw[1]), int(raw[2])
    currc = infile.readline().rstrip().split()
    currc = [int(i) for i in currc]
    solution=0
    notposs=[]
    for curr in range(1, maxv+1):
        sol=solve(curr, currc, 0)
        if sol!=0:
            solution+=1
            currc.append(curr)
            currc = sorted(currc)
    outline="Case #"+str(z) + ": "+str(solution) + "\n"
    print(outline)
    outfile.write(outline)

infile.close()
outfile.close()
