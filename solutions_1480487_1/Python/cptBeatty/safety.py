

def run():
    f=open("input.in")
    g=open("out.txt",'w')
    num = int(f.readline())
    for i in range(num):
        g.write("Case #%d: " % (i+1))
        vals = map(int,f.readline().split())
        N = vals[0]
        scores = vals[1:]
        total = sum(scores)
        copy = scores[:]
        copy.sort()
        needed  = 0
        curr =copy[0]
        for j in range(1,N):
            add = copy[j]-curr
            if (needed+(j)*add)>total:
                break
            else:
                needed += (j)*add
                curr = copy[j]
        cutoff=curr
        adj = 0
        for j in range(N):
            if scores[j]<=cutoff:
                adj+=1
        extra = total-needed        
        for j in range(N):
            if scores[j]>cutoff:
                g.write("0 ")
            else:
                needs=100.0*(cutoff-scores[j]+1.0*extra/adj)/total
                g.write("%f " % needs)
        g.write("\n")
        continue
    f.close()
    g.close()
    
