import math

def CASE(in1):
    X, R, C = map(int, in1.split())
    #print X, R, C
    rc = R * C
    result = "RICHARD"
    if X == 4:
        if (R >= 3) and (C >= 3) and (rc % 4 == 0):
            result =  "GABRIEL"
        else:
            result = "RICHARD"
    elif X == 3:
        if (R >= 2) and (C >= 2) and (rc % 3 == 0):
            result =  "GABRIEL"
        else:
            result = "RICHARD"
    else:
        if rc >= 1 and (rc % X == 0):
            result =  "GABRIEL"
        else:
            result = "RICHARD"
    return result
def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1, t + 1):
        in1 = IN.readline().strip() 
        OUT.write("Case #%i: %s\n" % (i, CASE(in1)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
