import sys
from math import ceil

def main(i,fin,fout):
    inp = map(int, fin.readline().strip().split())
    p = inp[2]
    s = inp[1]
    n = inp[0]
    arr = []
    potential = 0
    ans = 0
    for i in xrange(n):
        el = inp[i + 3]
        if ceil(el/3.0) >= p:
            ans += 1
            continue
        if ceil(el/3.0) < p - 1:
            continue
        if ceil(el/3.0) == p - 1:
            if el % 3 != 1 and ceil(el/3.0) > 0:
                potential += 1
    ans += min(s, potential)
    fout.write(str(ans))

if __name__ == '__main__':
    fin = open("bin.txt", "r")
    fout = open("bout.txt", "w")
    cases = int(fin.readline())
    for i in xrange(cases):
        fout.write("Case #%d: " %(i+1))
        main(i,fin,fout)
        fout.write("\n")

    fin.close()
    fout.close()
