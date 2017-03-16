import sys
import math

if len(sys.argv) == 1:
    print "Requires input file"
    sys.exit(1)

f_in = open(sys.argv[1], 'r')
lines = [l.strip() for l in f_in.readlines()[1:]]
f_in.close()

def can_beat_p(x, p):
    if math.ceil(x / 3.0) >= p:
        return x
    else:
        return None

def can_be_surprise(x, p):
    a = p
    b = (p - 2)
    c = x - a - b
    if can_beat_p(x, p):
        return x
    elif ((min(a, b, c) < 0 or max(a, b, c) > 10) or 
            (max(a, b, c) - min(a, b, c) > 2) or 
            a + b + c != x):
        return None
    else:
        return x

for i, line in enumerate(lines):
    numbers = [int(x) for x in line.split()]
    N = numbers[0]
    S = numbers[1]
    p = numbers[2]
    scores = numbers[3:]
    
    normals = [can_beat_p(x, p) for x in scores]
    surprises = [can_be_surprise(x, p) for x in scores]
    
    ssss = sum([1 for x in surprises if x])
    
    total = 0
    current_surprises = 0
    if p == 0:
        total = N
    else:
        for n, s in zip(normals, surprises):
            if n:
                total += 1
            elif current_surprises < S and s:
                total += 1
                current_surprises += 1
            
    print 'Case #%d: %d' % (i + 1, total)
    
