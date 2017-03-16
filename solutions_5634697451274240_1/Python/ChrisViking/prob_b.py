__author__ = 'Christian'

#fname = 'test_b.txt'
#fname = 'B-small-attempt0.in'
fname = 'B-large.in'

f = open(fname, 'r')
data = f.read().split('\n')
f.close()

res_file = open(fname + '.res', 'w')


def compute_steps(s):
    
    s = s.rstrip('+')
    if not s:
        return 0
    step = 1
    current = s[0]
    for c in s[1:]:
        if c != current:
            step += 1
            current = c
            
    return step


T = int(data[0])
for i in range(T):
    print >> res_file, "Case #%s: %s" % (i+1, compute_steps(data[i+1]))
    
res_file.close()