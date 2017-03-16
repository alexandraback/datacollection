import math, sys


quaternion = {
    "i": {"j": (True, "k"), "k": (False, "j") },
    "j": {"i": (False, "k"), "k": (True, "i") },
    "k": {"i": (True, "j"), "j": (False, "i") },
}

def q( a, b ):
    if a == (True, "1"):
        return b
    elif a == (False, "1"):
        return not b[0], b[1]
    elif b == (True, "1"):
        return a    
    elif b == (False, "1"):
        return not a[0], a[1]

    sign = (a[0] == b[0])
    if a[1] == b[1]:
        return ( not sign , "1")
    if sign:
        return quaternion[ a[1] ] [ b[1] ]
    else: 
        return quaternion[ b[1] ] [ a[1] ]

def q_str(str, sign = True):
    tmp = (sign, "1")
    for x in str:
        tmp = q(tmp, (True, x))
    return tmp

def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine


def main():

    def solve():
        strL_res = q_str( strL )
        #print strL_res, X
        if (strL_res[0] == True):
            if strL_res[1] == "1":
                return "NO"
            elif X % 4 != 2:
                return "NO"
        if (strL_res[0] == False):
            if strL_res[1] == "1":
                if X % 2 == 0:
                    return "NO"
            elif X % 4 != 2:
                return "NO"

        counts = [True for x in "ijk" if strL.count(x) > 0]
        if len(counts) < 2:
            return "NO"

        ### trying to get first True, "i"
        foundi = False
        foundj = False
        tmp = (True, "1")
        
        r = min(sys.maxint, X)
        Y =  X / r
        for y in xrange(Y):
            for x in xrange(r):
                for l in strL:
                    next_tmp = q( tmp, (True, l) )
                    #print tmp, l, next_tmp, foundi, foundj
                    tmp = next_tmp
                    if foundi == False:
                        if tmp == (True, "i"):
                            foundi = True
                            tmp =  (True, "1")
                    elif foundj == False:
                        if tmp == (True, "j"):
                            foundj = True
                            #print tmp, l, next_tmp, foundi, foundj
                            return "YES"                    

        return "NO"

    ############################################1
    T = int( raw_input() )
    for t in xrange(T):    
        L, X = map( int, raw_input().split(' ') )
        strL = raw_input()
        output( t, solve() )        


if __name__ == "__main__":
   main()