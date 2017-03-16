from itertools import permutations

t = int(raw_input())

for i in xrange(1, t + 1):
    N = int(raw_input())
    F = [0]
    F = F + [int(s) for s in raw_input().split(" ")]
    
    for j in reversed(xrange(2, N + 1)):
        found = False
        for k in permutations(range(1, N + 1), j):
            match = True
            match = match and (k[j-1] == F[k[0]] or k[1] == F[k[0]])
            match = match and (k[j-2] == F[k[j - 1]] or k[0] == F[k[j - 1]])
            if not match:
                continue
            for l in xrange(1, j - 1):
                match = match and (k[l - 1] == F[k[l]] or k[l + 1] == F[k[l]])
                if not match:
                    break
            if match:
                print "Case #{}: {}".format(i, j)
                found = True
                break
        if found:
            break
