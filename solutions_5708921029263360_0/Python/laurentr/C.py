import sys

with open(sys.argv[1], 'r') as f:
    for k in range(int(f.readline())):
        J, P, S, K = [int(i) for i in f.readline().split()]
        res = []
        counts_jp = {}
        counts_js = {}
        counts_ps = {}
        for j in range(1, J+1):
            for p in range(1, P+1):
                for s in range(1, S+1):
                    jp = str(j)+' '+str(p)
                    js = str(j)+' '+str(s)
                    ps = str(p)+' '+str(s)
                    counts_jp[jp] = 0
                    counts_js[js] = 0
                    counts_ps[ps] = 0
        
        for j in range(1, J+1):
            for p in range(1, P+1):
                for s in range(1, S+1):
                    jp = str(j)+' '+str(p)
                    js = str(j)+' '+str(s)
                    ps = str(p)+' '+str(s)
                    candidate = str(j)+' '+str(p)+' '+str(s)
                    if max(counts_jp[jp], counts_js[js], counts_ps[ps]) < K:
                        res.append(candidate)
                        counts_jp[jp] +=1
                        counts_js[js] +=1
                        counts_ps[ps] +=1
                         
        print 'Case #{}: {}'.format(k+1, str(len(res))+'\n'+'\n'.join(res))
