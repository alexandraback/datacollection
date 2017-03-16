def getDeg(p, i):
    cans = 0
    while i % p == 0:
        cans += 1
        i //= p
    return cans

def getM(p, l):
    cans = 0
    for i in l:
        cans = max(cans, getDeg(p, i))
    return cans

def getNums(p):
    m5 = getM(5, p)
    m3 = getM(3, p)
    m2 = getM(2, p)
    ans = [5]*m5 + [3]*m3
    nd = 3 - len(ans)
    ans += [4]*(m2 - nd)
    nd = 3 - len(ans)
    ans += [2]*nd
    return ans

def getAns(l):
    return "\n".join(["".join(map(str, getNums(l[i]))) for i in range(len(l))])


def main():
    FIN = open("input.txt", "r")
    FOUT = open("output.txt", "w")
    T = int(FIN.readline())
    for i in range(T):
        r, n, m, k = map(int, FIN.readline().split())
        l = [list(map(int, FIN.readline().split())) for i in range(r)]
        print("Case {0}#\n{1}".format(i + 1, getAns(l)), file = FOUT)
    FIN.close()
    FOUT.close()

if __name__ == "__main__":
    main()