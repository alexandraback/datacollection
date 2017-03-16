import sys
from time import time as ti

def pancake(ini,out):
    f = open(ini,'r')
    o = open(out,'w')
    T = int(f.readline())

    for t in range(T):
        s = list(f.readline())
        if "\n" in s:
            s.remove("\n")
        past = s[0]
        count = 0
        for mood in s:
            if mood != past:
                count+=1
            past = mood
        if mood == "-":
            count+=1
        o.write("Case #"+str(t+1)+": "+str(count)+"\n")
        print(str(s)+" Case #"+str(t+1)+": "+str(count))

def main(argv):
    ini = "B-large.in"
    out = "B-large.txt"
    start = ti()
    pancake(ini,out)
    end = ti()
    print (end-start)

if (__name__ == "__main__"):
    main(sys.argv[1:])


