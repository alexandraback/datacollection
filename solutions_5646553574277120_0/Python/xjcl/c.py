from time import clock
import sys
import math
# stderr isn't piped to a.out when we do  (py3 a.py < a.in) > a.out
print = lambda *s: sys.stderr.write(" ".join(str(m) for m in s)+"\n")

#---------------------------------------------

"""
1 4 30
1 5 10 17

"""

def run(data):

    c, v, a = data

    i = 1
    n = len(a)

    newcoins = math.ceil(math.log(a[0], c*2))
    print(newcoins)

    prefsum = int((c*2)**newcoins - 1 + c*a[0])

    while prefsum < v:

        print(prefsum, a[i] if i<n else "xxx", newcoins)

        # case we cannot reach next coin -> add new one
        if (i >= n or prefsum+1 < a[i]):
            assert i != 0
            #a = a[:i] + [prefsum+1] + a[i:]
            newcoins += 1
            print("mint of value ", prefsum+1)
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

