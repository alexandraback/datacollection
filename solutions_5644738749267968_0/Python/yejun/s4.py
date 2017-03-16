import sys

f = open(sys.argv[1]) if len(sys.argv)>1 else sys.stdin

total = int(f.readline().strip())

def play1(naomi, ken, n1, n2, k1, k2):
    if n1 == n2:
        return 1 if naomi[n1] > ken[k1] else 0
    if naomi[n1] > ken[k1]:
        return 1 + play1(naomi, ken, n1+1, n2, k1+1, k2)
    return play1(naomi, ken, n1+1, n2, k1, k2-1)

def play2(naomi, ken, n1, n2, k1, k2):
    if n1 == n2:
        return 1 if naomi[n1] > ken[k1] else 0
    if naomi[n2] > ken[k2]:
        return 1 + play2(naomi, ken, n1, n2-1, k1+1, k2)
    return play2(naomi, ken, n1, n2-1, k1, k2-1)

for i in range(total):
    sys.stdout.write("Case #%d: " % int(i+1))
    n = int(f.readline().strip())
    naomi = sorted([float(j) for j in f.readline().strip().split()])
    ken = sorted([float(j) for j in f.readline().strip().split()])
    print(play1(naomi, ken, 0, n-1, 0, n-1), play2(naomi, ken, 0, n-1, 0, n-1))
