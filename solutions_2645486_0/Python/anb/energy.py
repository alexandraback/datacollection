from sys import stdin

def read_ints(): return map(int, stdin.readline().split())

def main():
    cases = int(stdin.readline())
    for case in xrange(1, cases + 1):
        E, R, N = read_ints()
        v = read_ints()
        
        ans = 0
        c = [(0, E)]
        for i in xrange(N):
            #print i
            n = []
            for elem in c:
                gain, energy = elem
                cm = 0
                for e in xrange(energy + 1):
                    t = v[i] * e
                    if cm < t: cm = t
                    g = gain + t
                    if g > ans: ans = g
                    left = energy - e + R
                    if left > E: left = E
                    if g > ans - 50:
                        n.append((g, left))
            c = n

        print('Case #{}: {}'.format(case, ans))
        
main()