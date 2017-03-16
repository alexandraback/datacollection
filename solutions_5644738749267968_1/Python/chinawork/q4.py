__author__ = 'cni'

def cal_war(naomi, ken):
    points = len(ken)

    ken = sorted(ken)

    for n in naomi:
        for k in xrange(len(ken)):
            if n < ken[k]:
                points -= 1
                ken.pop(k)
                break

    return points

def dec_war(naomi, ken):
    points = 0

    naomi = sorted(naomi, reverse=True)
    ken = sorted(ken, reverse=True)

    for n in naomi:
        for k in xrange(len(ken)):
            if n > ken[k]:
                points += 1
                ken.pop(k)
                break

    return points

f = open('test.txt')
lines = f.readlines()
f.close()

case_num = int(lines[0])
idx = 1

f = open('out.txt', 'w')

for i in xrange(1, case_num + 1):
    num = int(lines[idx])
    idx += 1

    naomi = [float(j) for j in lines[idx].split()]
    idx += 1
    ken = [float(j) for j in lines[idx].split()]
    idx += 1

    w = cal_war(naomi, ken)
    d = dec_war(naomi, ken)

    f.write('Case #%d: %d %d\n' % (i, d, w))
f.close()
