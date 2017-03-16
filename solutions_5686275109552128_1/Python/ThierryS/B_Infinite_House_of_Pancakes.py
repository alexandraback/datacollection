import sys

def Pancake():
    T = int(sys.stdin.readline())
    for case in range(1,T+1):

        D = int(sys.stdin.readline().strip())
        P = list(map(int, sys.stdin.readline().strip().split(' ')))
        ans = max(P)

        Z = 2
        while Z < ans:
            ans = min(ans, sum([(x - 1) // Z for x in P]) + Z)
            Z += 1

        print 'Case #%d: %s' % (case, ans)
        
if __name__ == '__main__':
    Pancake()
