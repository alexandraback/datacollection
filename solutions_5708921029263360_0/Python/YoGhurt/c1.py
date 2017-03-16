def solve(j, p, s, k, solutioncounter, res):
    outfits = []
    jmod = 0
    pmod = 0
    smod = 0
    minflag = ""
    if j<= p and j<=s:
        minflag = "j"
    elif p<=j and p<=s:
        minflag = "p"
    elif s<=j and s<=p:
        minflag = "s"
    while jmod < j and smod < s and pmod < p:
        for x in range(min(j - jmod, k)):
            for y in range(min(p - pmod, k)):
                for z in range(min(s - smod, k)):
                        outfits.append("{} {} {}\n".format(x + jmod + 1, y+pmod + 1, z+smod + 1))
        if minflag != "j":
            jmod += k
        if minflag != "p":
            pmod += k
        if minflag != "s":
            smod += k
    res.write("Case #{}: {}\n".format((solutioncounter + 1), len(outfits)))
    res.write(''.join(outfits))

def main():
    f = open("C://CodeJam/c2.in", 'r')
    res = open("C://CodeJam/c2.out", 'w')
    T = int(f.readline())
    print T
    for x in range(T):
        print x
        a = f.readline()
        a = a.split()
        j = int(a[0])
        p = int(a[1])
        s = int(a[2])
        k = int(a[3])
        solve(j, p, s, k, x, res)
    f.close()
    res.close()

if __name__ == "__main__":
    main()
