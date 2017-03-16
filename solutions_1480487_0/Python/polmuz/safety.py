import sys

def prob(p, r, t, sr):
    r = (float(sr) + float(t) - float(r) * float(p) - float(p)) * 100.0 / (float(r) * float(t) + float(t))
    # if r < 0:
    #     return 0
    return r

# print prob(20, 1, 30), prob(10, 1, 30)
# print prob(10, 1, 10), prob(0, 1, 10)
# print prob(25, 3, 100)
# print prob(24, 2, 75), prob(30, 2, 75), prob(21, 2, 75)


def all_probs(points):
    t = sum(points)
    r = len(points) - 1
    probs = []
    for p in points:
        probs.append(prob(p, r, t, t))
    ns = [x for x in probs if x < 0]
    if len(ns) > 0:
        r = len(points) - 1 - len(ns)
        sp = sum([points[i] for i in range(len(points)) if probs[i] >= 0])
        print sp
        for i in range(len(probs)):
            if probs[i] < 0:
                probs[i] = 0.0
            else:
                probs[i] = prob(points[i], r, t, sp - points[i])
    return probs

# print all_probs([20, 10])
# print all_probs([10, 0])
# print all_probs([25, 25, 25, 25])
# print all_probs([24, 30, 21])

fin = open(sys.argv[1])
fout = open(sys.argv[2], 'w')

cases = int(fin.readline().strip())

for casen in range(1, cases+1):
    print casen
    fout.write("Case #%d: " % casen)
    points = [int(p) for p in fin.readline().strip().split(' ')[1:]]
    probs = all_probs(points)
    fout.write(" ".join([str(p) for p in probs]) + '\n')

fout.close()
