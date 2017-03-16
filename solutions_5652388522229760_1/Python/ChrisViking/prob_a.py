__author__ = 'Christian'

#fname = 'test_a.txt'
#fname = 'A-small-attempt0.in'
fname = 'A-large.in'

f = open(fname, 'r')
data = f.read().split('\n')
f.close()

res_file = open(fname + '.res', 'w')


def compute_sleep(n):
    res = set()
    
    if n == 0:
        return "INSOMNIA"
    
    current = 0
    i = 0
    while (i<1000000):
        current += n
        res = res.union(set(str(current)))
        if len(res) == 10:
            return current
    return "INSOMNIA"

T = int(data[0])
for i in range(T):
    print >> res_file, "Case #%s: %s" % (i+1, compute_sleep(int(data[i+1])))
    
res_file.close()