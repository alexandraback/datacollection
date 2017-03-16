from time import clock
import sys
import itertools

# stderr isn't piped to a.out when we do  (py3 a.py < a.in) > a.out
print = lambda *s: sys.stderr.write(" ".join(str(m) for m in s)+"\n")

#---------------------------------------------

"""
bla brute force

faster with pypy3 ;)
"""

# http://stackoverflow.com/questions/2970520
def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count



def run(data):

    it, keys, target = data

    cases = 0
    maxi = 0
    sumval = 0

    for s in itertools.product(keys, repeat=it):

        val = occurrences("".join(s), target)

        cases += 1
        sumval += val
        maxi = max(val, maxi)


    avg = sumval / cases

    return maxi - avg

#---------------------------------------------

def read_case():
    _, _, it = [int(n) for n in input().split()]
    keys = input()
    target = input()
    return (it, keys, target)

if __name__ == "__main__":
    for i in range(int(input())):
        outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
        print(outstr+" @ t="+str(clock()))
        sys.stdout.write(outstr+"\n")

