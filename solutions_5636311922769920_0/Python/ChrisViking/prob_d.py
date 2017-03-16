__author__ = 'Christian'

#fname = 'test_d.txt'
fname = 'D-small-attempt1.in'
#fname = 'D-large.in'

f = open(fname, 'r')
data = f.read().split('\n')
f.close()

res_file = open(fname + '.res', 'w')

# there is an invariance of positioning after each repetition
# so for all i in [1,K], at complexity C, the tile of index 
# (K^C-1)/(K-1)*(i-1)+1 is the same as tile i at complexity 1.
# So when S=K the problem can always be solved

def compute_sequence(K, C, S):
    
    if K == 1:
        return '1'
    
    if K != S:
        print "not treated yet", K, C, S
        return "IMPOSSIBLE"
    
    pow=1
    for i in range(C):
        pow *= K
    
    return ' '.join([str((pow-1)/(K-1)*(i-1)+1) for i in range(1,K+1)])


T = int(data[0])
for i in range(T):
    K, C, S = [int(x) for x in data[i+1].split()]
    print >> res_file, "Case #%s: %s" % (i+1, compute_sequence(K, C, S))
    
res_file.close()