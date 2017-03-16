from heapq import heapify,heappush,heappop

def run():
    f=open("input.in")
    g=open("out.txt",'w')
    num = int(f.readline())
    
    for ind in range(num):
        sums = {}
        picks = 0
        flag = False
        g.write("Case #%d:\n" % (ind+1))
        vals = map(int,f.readline().split())[1:]
        for i in range(2**20):
            tot = 0
            for j in range(20):
                if i & 2**j:
                    tot+= vals[j]
            if tot in sums:
                flag = True
                picks = (i,sums[tot])
                break
            else:
                sums[tot]=i
        if flag:
            (m,n)=picks
            for q in range(20):
                if m & 2**q:
                    g.write("%d " % vals[q])
            g.write("\n")
            for q in range(20):
                if n & 2**q:
                    g.write("%d " % vals[q])
            g.write("\n")
        else:
            g.write("Impossible\n")
        continue
    f.close()
    g.close()
    
