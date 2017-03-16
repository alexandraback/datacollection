import sys

def should_upgrade(C, F, X, rate):
    t_to_upgrade = C/rate
    t_with_upgrade = X/(rate + F)
    t_to_end = X/rate
    t_to_end_upgrade = t_to_upgrade + t_with_upgrade
    if t_to_end > t_to_end_upgrade:
        return True
    else:
        return False

def solve(C,F,X):
    rate = 2.0
    time = 0.0
    while True:
        if should_upgrade(C,F,X,rate):
            time += C/rate
            rate = rate + F
        else:
            return X/rate + time

path = sys.argv[1]

lines = [line.strip() for line in open(path)]

ninput = int(lines[0])

lines = lines[1:]

valsarr = [[float(x) for x in line.split()] for line in lines]

for (ix,vals) in enumerate(valsarr):
    (C, F, X) = vals
    print "Case #%d: %0.7f" % (ix+1,solve(C,F,X))

