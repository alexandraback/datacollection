def G(i, leftE, vs, E, R, N):
    if i >= N: return 0
    
    ans = 0
    for j in xrange(0, leftE+1):
        ans = max(vs[i]*j+G(i+1, min(E, leftE-j+R), vs, E, R, N), ans)
    return ans

def main():
    T = int(raw_input())
    for ti in xrange(T):
        ERN = [int(x) for x in raw_input().split()]
        E = ERN[0]
        R = ERN[1]
        N = ERN[2]
        vs = [int(x) for x in raw_input().split()]
        ans = G(0, E, vs, E, R, N)
        print "Case #{0}: {1}".format(ti+1, ans)
    pass

if __name__ == "__main__":
    main()
