from time import clock
import sys
import math
# stderr isn't piped to a.out when we do  (py3 a.py < a.in) > a.out
print = lambda *s: sys.stderr.write(" ".join(str(m) for m in s)+"\n")

#---------------------------------------------

"""

"""

def run(data):

    r, c, w = data

    # if w == 1:
    #     return r*c

    guesses = 0

    # OOOOH THE PROBLEM STATEMENT SAID HORIZONTALLY

    for i in range(r-1):
        guesses += math.floor(c/w)

    # optimal: is on last row
    guesses += (w-1) + math.ceil(c/w)

    return guesses

#---------------------------------------------

def read_case():
    return [int(n) for n in input().split()]

if __name__ == "__main__":
    for i in range(int(input())):
        outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
        print(outstr+" @ t="+str(clock()))
        sys.stdout.write(outstr+"\n")

