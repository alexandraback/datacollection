def solve(l):
    all_combos = []
    used_ik = dict()
    used_jk = dict()
    used_ij = dict()
    for i in range(l[0]):
        for j in range(l[1]):
            for k in range(l[2]):
                if used_ik.get((i,k),0)==l[3]:
                    continue
                if used_jk.get((j,k),0)==l[3]:
                    continue
                if used_ij.get((i,j),0)==l[3]:
                    continue
                all_combos.append((str(i+1),str(j+1),str(k+1)))
                used_ik[(i,k)] = used_ik.get((i,k), 0)+1
                used_jk[(j,k)] = used_jk.get((j,k), 0)+1
                used_ij[(i,j)] = used_ij.get((i,j), 0)+1
    return str(len(all_combos))+"\n"+"\n".join([" ".join(m) for m in all_combos])
    
        
        

filename = "C-small-attempt2.in"
f = open(filename,"r")
fout = open(filename.replace(".in", ".out"), "w")
N = int(f.readline())
for i in range(N):
    res = solve([int(i) for i in f.readline().strip().split()])
    print("Case #{}:".format(i+1), res)
    print("Case #{}:".format(i+1), res,file=fout)
f.close()
fout.close()