__author__ = 'cni'

def cal(C, F, X):
    speed = 2.0
    remain = X
    clock = 0.0

    while (remain / speed > (C / speed) + (remain / (speed + F))):
        clock += C / speed
        speed += F

    clock += remain / speed

    return clock

f = open('B-small-attempt0.in.txt')
lines = f.readlines()
f.close()

case_num = int(lines[0])

f = open('out.txt', 'w')
for i in xrange(1, case_num + 1):
    line = lines[i]
    C, F, X = tuple([float(j) for j in line.split()])

    res = cal(C, F, X)

    f.write('Case #%d: %.7f\n' % (i, res))
f.close()