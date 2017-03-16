def func(r, k):
    return 2 *k * k + (2 * r - 1) * k

def get_ans(r, t):
    lb = 1
    ub = t + 1
    ret = -1
    while lb < ub:
        mid = (lb + ub) / 2
        
        if (func(r, mid) > t):
            ub = mid
        else:
            lb = mid + 1
            ret = mid
    return ret

fin = file('input.txt', 'r')

line = fin.readline();
T = int(line)
nc = 0

while T > 0:
    line = fin.readline()
    T = T - 1
    lines = line.split()
    r = int(lines[0])
    t = int(lines[1])
    nc = nc + 1
    print "Case #%d: %d" %(nc,get_ans(r, t))
fin.close()
