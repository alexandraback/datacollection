import sys


def main():
    infile = open(sys.argv[1])
    outfile = open(sys.argv[1][:-2] + 'out', 'w')
    numcases = int(infile.readline())

    for case in range(numcases):
        E,R,N = (int(k) for k in infile.readline().split())
        V = [int(k) for k in infile.readline().split()]
        use = [0]*N
        if R > E:
            R=E
        energy = E
        for a in range(N):
            b=a
            while b<N and V[b]<=V[a]:
                b+=1
            if b>=N:
                use[a] = energy
            else:
                use[a] = max(min((b-a)*R-(E-energy),energy),0)
            energy = min((energy - use[a] + R),E)
        out = sum(use[i]*V[i] for i in range(N))
        print('Case #%d:' % (case + 1), out, file=outfile)





if __name__ == '__main__':
    main()
