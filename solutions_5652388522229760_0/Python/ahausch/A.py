import sys

def solve(N):
    if (N == 0):
        return 'INSOMNIA'
    i = 1
    n = N

    s = {}

    while True:
        for c in str(n):
            s[c] = True
            
        if len(s.keys()) == 10:
            return n

        i = i + 1
        n = N * i
        
fin = open(sys.argv[1], 'r')

T = int(fin.readline())

for t in range(1, T + 1):
    N = int(fin.readline())
    print("Case #{0}: {1}".format(t, solve(N)))

fin.close()

