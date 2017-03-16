from time import clock
import sys
import math
# stderr isn't piped to a.out when we do  (py3 a.py < a.in) > a.out
print = lambda *s: sys.stderr.write(" ".join(str(m) for m in s)+"\n")

#---------------------------------------------

"""

"""

def run(data):

    _, c, w = data

    return (w-1) + math.ceil(c/w)

#---------------------------------------------

def read_case():
    return [int(n) for n in input().split()]

if __name__ == "__main__":
    for i in range(int(input())):
        outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
        print(outstr+" @ t="+str(clock()))
        sys.stdout.write(outstr+"\n")

