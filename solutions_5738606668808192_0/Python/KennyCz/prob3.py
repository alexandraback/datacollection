import sys
import random
from sets import Set

def Generate(poly):
    ans = Set([tuple(poly)])
    while len(ans) < 50:
        a = random.randint(1, len(poly)-1)
        b = random.randint(1, len(poly)-1)
        if a - b % 3 == 0 and poly[a] != poly[b]:
            poly[a], poly[b] = poly[b], poly[a]
            ans |= Set([tuple(poly)])
    return ans



if __name__ == "__main__":

    T = int(sys.stdin.next())
    N, J = map(int, sys.stdin.next().split(" "))

    pol1 = 3*[1] + (N-6)*[0] + 3*[1]
    jamcoins = Generate(pol1)

    print "Case #1:"
    divs = [x*x+x+1 for x in range(2,11)]


    for jc in jamcoins:
        print  "".join(map(str, jc)) ," ".join(map(str,divs))



