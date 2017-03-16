import numpy as np

def nth_row(n, m):
    return np.array([0]*n + [1, -1] + [0]*(m-n-2))

def left_array(m):
    rows = np.array(map(lambda i: nth_row(i, m), range(m-1)))
    return np.concatenate((rows, np.array([[1]*m])))

def right_array(conts):
    vals = []
    total = sum(conts)
    for i in range(1, len(conts)):
        vals.append((float(conts[i])-conts[i-1])/total)
    vals.append(1)
    return np.array(vals)

def solve(conts):
    left = left_array(len(conts))
    right = right_array(conts)
    return list(np.linalg.solve(left, right))

def rem_negatives(solved):
    diff = 0
    for i, s in enumerate(solved):
        if s < 0:
            diff += -s
    solved = map(lambda a: a+diff, solved)
    return solved

nt = int(raw_input())
for i in range(nt):
    inp = raw_input().strip().split()
    conts = map(int, inp[1:])
    solved = solve(conts)
    solved = rem_negatives(solved)
    solved = map(lambda n: n*100, solved)
    print "Case #" + str(i+1) + ":",
    for n in solved:
        print n,
    print 
