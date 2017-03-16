from time import clock
import sys
import math
# stderr isn't piped to a.out when we do  (py3 a.py < a.in) > a.out
print = lambda *s: sys.stderr.write(" ".join(str(m) for m in s)+"\n")

#---------------------------------------------

"""
idea: keep the maximum amount we can make as prefsum
    so if we had C=2, coins 1 2 3 5, prefsum is 2+4+6+10
    then see if the next coin in a can already be made*, else add it
        *: prefsum+1 >= a[i]

we consider the case a[0] != 1 separately
    (i.e. we pre-calculate newcoins and prefsum in O(1))
    we don't need case analysis: log(1,x)==0==newcoins as intended

i'm skeptical as to whether this will work for the large input.
my solution isn't a cheap shot, but all that differs from my
    small solution is me adding a 'times c' everywhere :/
    (actually all c*2's in the log should've been 1+c, d'oh)
    (change of plan, do a[0] != 1 via looop)

plus this solution is in O(n), which is too good to be true
"""

def run(data):

    c, v, a = data

    i = 1
    n = len(a)

    newcoins = math.ceil(math.log(a[0], 1+c))
    print(newcoins)


    prefsum = 0
    for k in range(newcoins):
        prefsum += c * int((1+c)**k)

    prefsum += c * a[0]


    while prefsum < v:

        #print(prefsum, a[i] if i<n else "xxx", newcoins)

        # case we cannot reach next coin -> add new one
        if (i >= n or prefsum+1 < a[i]):
            assert i != 0
            #a = a[:i] + [prefsum+1] + a[i:]
            newcoins += 1
            #print("mint of value ", prefsum+1)
            prefsum += c * (prefsum+1)

        else:
            prefsum += c*a[i]
            i += 1


    return str(newcoins)

#---------------------------------------------

def read_case():
    c, _, v = [int(n) for n in input().split()]
    a = [int(n) for n in input().split()]
    return (c, v, a)

if __name__ == "__main__":
    for i in range(int(input())):
        outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
        print(outstr+" @ t="+str(clock()))
        sys.stdout.write(outstr+"\n")

