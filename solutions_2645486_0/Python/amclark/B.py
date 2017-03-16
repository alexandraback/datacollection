import sys

def rl():
    return sys.stdin.readline().strip()

def main():
    T = int(rl())
    get1 = lambda x: x[1]
    for i_ in range(1, T+1):
        E, R, N = map(int, rl().split())
        values = map(int, rl().split())
        energy = [[float('inf'),float('inf')] for _ in range(N)]
        total = 0
        ranks = sorted(enumerate(values), key=get1, reverse=True)
        for i, v in ranks:
            used = min(E, *energy[i])
            total += used*v
            energy[i][0] = 0
            for j in range(0, i):
                energy[j][1] = min(R*(i-j), energy[j][1])
            for j in range(i+1, len(energy)):
                energy[j][0] = min(energy[j-1][0]+R, energy[j][0])
        print 'Case #%d: %d' % (i_, total)
            
if __name__ == '__main__':
    main()
