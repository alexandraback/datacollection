import sys
from time import time as ti

def fractile(ini,out):
    f = open(ini,'r')
    o = open(out,'w')
    T = int(f.readline())

    for t in range(T):
        K,C,S = f.readline().split(' ')
        K = int(K)
        C = int(C)
        S = int(S)
        pos = []
        if K == 1:
            o.write("Case #"+str(t+1)+": 1\n")
            continue
        if ((C == 1) and (S<K)) or ((C>1) and (S<(K-1))):
            o.write("Case #"+str(t+1)+": IMPOSSIBLE\n")
            continue
        if C == 1:
            for i in range(K):
                pos.append(str(i+1))
            o.write("Case #"+str(t+1)+": "+" ".join(pos)+"\n")
            continue
        else:
            for i in range(K-1):
                pos.append(str(i+2))
            o.write("Case #"+str(t+1)+": "+" ".join(pos)+"\n")

def main(argv):
    ini = "D-small-attempt0.in"
    out = "D-small-attempt0.txt"
    start = ti()
    fractile(ini,out)
    end = ti()
    print (end-start)

if (__name__ == "__main__"):
    main(sys.argv[1:])
