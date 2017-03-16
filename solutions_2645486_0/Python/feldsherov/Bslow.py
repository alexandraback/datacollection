def getAns(e, r, v):
    d = [[0 for i in range(e + 1)] for i in range(len(v) + 1)]
    for ps in range(len(v)):
        for ce in range(e + 1):
            for te in range(ce + 1):
                d[ps + 1][min(e, ce - te + r)] = max(d[ps + 1][min(e, ce - te + r)], d[ps][ce] + v[ps]*te)
    return max(d[len(v)])


def main():
    FIN = open("input.txt", "r")
    FOUT = open("output.txt", "w")
    T = int(FIN.readline())
    for i in range(T):
        e, r, n = map(int, FIN.readline().split())
        v = list(map(int, FIN.readline().split()))
        print("Case #{0}: {1}".format(i + 1, getAns(e, r, v)), file = FOUT)
    FIN.close()
    FOUT.close()

if __name__ == "__main__":
    main()