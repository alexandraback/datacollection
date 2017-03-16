N = 3000
C = [[]]
Csum = []
def init():
    for i in range(N):
        C.append([1])
        Csum.append([1])
        for j in range(1, i):
            C[i].append(C[i-1][j] + C[i-1][j-1])
            Csum[i].append(Csum[i][j-1] + C[i][j])
        C[i].append(1)
        Csum[i].append(Csum[i][i-1] + 1)
            

def solve(n, x, y):
    h = 0
    while n >= 2 * h + 1:
        n -= 2 * h + 1
        h += 2
    h -= 2
    if x + y <= h and y - x <= h:
        return 1.0
    if not (x + y <= (h + 2) and (y - x) <= (h + 2)):
        return 0.0
    if n == 0:
        return 0.0

    h += 2
    if n <= h:
        if y + 1 > n:
            return 0.0
        return (Csum[n][n] - Csum[n][y] + 0.0) / 2 ** n
    else:
        if y + 1 <= n - h:
            return 1.0
        return (Csum[2 * h - n][2 * h - n] - Csum[2 * h - n][y - (n - h)]) / 2.0 ** (2 * h - n)

f = open('B-small-attempt0.in')
T = int(f.readline().split()[0])

init()

for t in range(1,T+1):
    [n, x, y] = [int(x) for x in f.readline().split()]
    ans = solve(n, x, y)
    print "Case #%d: %.10f" % (t, ans)
