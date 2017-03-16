f = open("pancakes.large.in", "r")

T = int(f.readline())
C = []
R = []

for i in range(0, T):
    S = f.readline().strip()
    a = [0 for j in range(0, len(S))]
    k = 0
    for j in S:
        if j == '+':
            a[k] = 1
        k += 1
    C.append(a)

f.close()

def flip(r, n):
    r2 = list(r)
    for i in range(0, n):
        r2[i] = 1 - r[n-i-1]
    return r2

def check(r):
    return sum(r) == len(r)

def optimal_fast(r):
    first = r[0]
    l = len(r)
    if check(r):
        return 0
    for i in range(0, l):
        if r[i] != first:
            r_flip = flip(r, i)
            return 1 + optimal_fast(r_flip)
    return 1

def optimal(r, current_best, depth):
    first = r[0]
    l = len(r)
    if check(r):
        return 0
    elif ( current_best < depth ):
        return 999
    result = current_best
    for i in range(0, l):
        if r[i] != first:
            r_flip = flip(r, i)
            o = 1 + optimal(r_flip, result, depth+1)
            if ( o < result ):
                result = o
            first = r[i]
    r_flip = flip(r, l)
    o = 1 + optimal(r_flip, result, depth+1)
    if ( o < result ):
        result = o

    return result


def optimal_full(r, current_best, depth):
    first = r[0]
    l = len(r)
    if ( current_best < depth ):
        return 100
    elif check(r):
        return 0
    result = current_best
    for i in range(0, l):
        if True:
            r_flip = flip(r, i)
            o = 1 + optimal_full(r_flip, result, depth+1)
            if ( o < result ):
                result = o
            first = r[i]
    r_flip = flip(r, l)
    o = 1 + optimal_full(r_flip, result, depth+1)
    if ( o < result ):
        result = o

    return result

print "start"

for i in range(0, len(C)):
    print "test: " + str(i)
    #o1 = optimal(C[i], 999, 0)
    o1 = optimal_fast(C[i])
    R.append(o1)

print "end"

f = open("pancakes.out", "w")

for m in range(0, T):
    f.write("Case #" + str(m + 1) + ": " + str(R[m]) + "\n")

        
f.close()

print "done"
