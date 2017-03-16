def readints(): return map(int, raw_input().split())

# multiplication table for positive entries (take representative mod 4 for the quotient by {+1,-1})
a = [
        [0, 1, 2, 3],
        [1, 4, 3, 6],
        [2, 7, 4, 1],
        [3, 2, 5, 4]
]

d = {"i": 1, "j": 2, "k": 3}

A = [[0]*8 for i in range(8)]

for i in range(8):
    for j in range(8):
        A[i][j] = (a[i%4][j%4] + (i/4 + j/4)*4) % 8

At = zip(*A) # transpose multiplication table, for the group Q_8^op

def mult(a, b):
    return A[a][b]

def find(target, word, table):
    p = 0
    for i, c in enumerate(word):
        p = table[p][c]
        if p == target:
            return i + 1

def valid_parity(prod, power):
    # returns prod ** power == -1
    if prod == 4 and power % 2 == 1:
        return True
    if prod % 4 != 0 and power % 4 == 2:
        return True
    return False

def solve(L, X, W):
    # check parity of entire string
    vals = [d[c] for c in W]
    prod = reduce(mult, vals)
    if not valid_parity(prod, X):
        return False
        
    M = 4 # largest possible order, thanks Lagrange!
    S = vals * 4
    left = find(1, S, A)
    right = find(3, S[::-1], At)
    if left and right and left + right <= L * X - 1: # enough room for a "j" in the middle
        return True
    return False
    
T, = readints()
for case_num in range(1, T+1):
	L, X = readints()
	W = raw_input().strip()
	print "Case #%d: %s" % (case_num, "YES" if solve(L, X, W) else "NO")