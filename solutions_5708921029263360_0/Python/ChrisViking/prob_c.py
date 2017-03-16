__author__ = 'Christian'

#fname = 'test_c.txt'
fname = 'C-small-attempt1.in'
#fname = 'C-large.in'

f = open(fname, 'r')
data = f.read().split('\n')
f.close()

res_file = open(fname + '.res', 'w')

def fashion(J, P, S, K):
    print (J, P, S, K)
    
    used_jp = {}
    used_js = {}
    used_ps = {}
    possible = []
    for j in range(J):
        for p in range(P):
            if (j,p) not in used_jp:
                used_jp[(j,p)] = 0
            if used_jp[(j,p)] == K:
                continue
            for s in range(S):
                if (j,s) not in used_js:
                    used_js[(j,s)] = 0
                if (p,s) not in used_ps:
                    used_ps[(p,s)] = 0
                if used_jp[(j,p)] == K or used_js[(j,s)] == K or used_ps[(p,s)] == K:
                    continue
                possible.append('%s %s %s' % (j+1, p+1, s+1))
                used_jp[(j,p)] += 1
                used_js[(j,s)] += 1
                used_ps[(p,s)] += 1
                
    return ('%s\n' % len(possible)) + '\n'.join(possible)
                

T = int(data[0])
for i in range(T):
    J, P, S, K = data[i+1].split(' ')
    J = int(J)
    P = int(P)
    S = int(S)
    K = int(K)
    res = fashion(J, P, S, K)
    print >> res_file, "Case #%s: %s" % (i+1, res)
    
res_file.close()