import math

def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine


def main():
    T = int( raw_input() )

    for t in xrange(T):    
        X, R, C = map( int, raw_input().split(' ') )
        if X >= 7:
            output(t, "RICHARD")
            continue
        if R*C % X:
            output(t, "RICHARD")
            continue            
        sqrSide = (X-1) / 2 + 1
        #print "sqrSide=", sqrSide
        if R < sqrSide or C < sqrSide:
            output(t, "RICHARD")
            continue

        if X == 1:
            output(t, "GABRIEL")
            continue

        if X == 4 and min(R, C) == 2:
            output(t, "RICHARD")
            continue

        if X == 6 and min(R, C) == 3:
            output(t, "RICHARD")
            continue

        if X == 5 and min(R, C) == 3 and max(R, C) == 5:
            output(t, "RICHARD")
            continue


        output(t, "GABRIEL")

if __name__ == "__main__":
   main()