import sys
from time import time as ti

def sheep(ini,out):
    f = open(ini,'r')
    o = open(out,'w')
    T = int(f.readline())
    
    for t in range(T):
        digits = ['1','2','3','4','5','6','7','8','9','0']
        N = int(f.readline())
        Ns = 0
        count = 1
        while True:
            if (count>1e6):
                o.write("Case #"+str(t+1)+": INSOMNIA\n")
                break
            if (len(digits)==0):
                o.write("Case #"+str(t+1)+": "+str(Ns)+"\n")
                break
            Ns += N
            elim = []
            for d in digits:
                if d in str(Ns):
                    elim.append(d)
            for d in elim:
                if d in digits:
                    digits.remove(d)
            count += 1
        print("Case #"+str(t+1)+": "+str(count))
def main(argv):
    ini = "A-small-attempt0.in"
    out = "A-small-attempt0.txt"
    start = ti()
    sheep(ini,out)
    end = ti()
    print (end-start)

if (__name__ == "__main__"):
    main(sys.argv[1:])
