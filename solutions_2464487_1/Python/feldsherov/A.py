def getAns(sr, t):
    l, m, r = 0, 0, 10**20
    while r - l > 1:
        m = (l + r) // 2
        if (2*sr + 2*m - 2)*m + m > t:
            r = m
        else:
            l = m
    return l

def main():
    FIN = open("input.txt", "r")
    FOUT = open("output.txt", "w")
    T = int(FIN.readline())
    for i in range(T):
        r, t = map(int, FIN.readline().split())
        print("Case #{0}: {1}".format(i + 1, getAns(r, t)), file = FOUT)
    FIN.close()
    FOUT.close()


if __name__ == "__main__":
    main()
    