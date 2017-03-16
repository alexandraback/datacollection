import os
f_inp = 'inp_2.txt'
f_out = 'out_2.txt'
f=open(f_inp)
f_o = open(f_out, 'w')
def next_line(f):
    line = f.readline()
    if line:
        line = line.strip()
    return line

def get_num_bf(a, b, k):
    k = min(a,b,k)
    num = k*b + k*(a-k)
    for x in range(k,a):
        for y in range(k,b):
            if x == y:
                continue
            if x&y < k:
                num+=1
    return num

def get_num(a, b, k):
    k = min(a,b,k)
    num = k*b + k*(a-k)
    for x in range(k,a):
        for y in range(k,b):
            if x == y:
                continue
            if x&y < k:
                num+=1
    return num

num_tc = int(next_line(f))
resp = 'Case #%s: %s'
for i in xrange(1,num_tc+1):
    a,b,k = [int(_) for _ in next_line(f).split(' ')]
    res = get_num(a,b,k)
    out = resp % (i, res)
    f_o.write('%s\n' % out)
    print out
f.close()
f_o.close()
