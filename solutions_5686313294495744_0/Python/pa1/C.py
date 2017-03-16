def t(sl, rl):
    ufw = list(set([l[0] for l in sl]))
    usw = list(set([l[1] for l in sl]))
    for p in rl:
        if p[0] in ufw and p[1] in usw:
            pass
        else:
            return False
    return True

def g(l):
    i = 0
    ans = 0
    while i < pow(2, len(l)):
        sl = []
        rl = []
        j = len(l)
        k = i
        while j > 0:
            if k % 2 == 0:
                sl.append(l[j - 1])
            else:
                rl.append(l[j - 1])
            k = k / 2
            j -= 1
        if t(sl, rl):
            ans = max(ans, len(rl))
        i += 1
    return ans

def main():
    T = int(raw_input())
    for t in range(1, T + 1):
        N = int(raw_input())
        l = []
        for k in range(N):
            u = raw_input().strip().split()
            l.append(u)
        print "Case #{0}: {1}".format(t, g(l))

if __name__ == "__main__":
    main()