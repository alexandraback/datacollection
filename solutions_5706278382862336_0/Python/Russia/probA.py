

import sys
import math

def gcd(a, b):
    if b < a:
        a, b = b, a
    q = b / a
    r = b % a
    while r != 0:
        b = a
        a = r
        q = b / a
        r = b % a
    return a

def check(a):
    return a == 2**int(math.log(a, 2))

def resolve(line, count, out):
    out.write("Case #%d: " % (count))
    
    tokens = line.strip().split("/")
    A = int(tokens[0])
    B = int(tokens[1])
    C = gcd(A, B)
    A = A / C
    B = B / C
    if not check(B):
        out.write("impossible\r\n")
        return

    out.write(str(int(math.ceil(math.log(float(B)/A, 2)))))
    out.write("\r\n")
    

if __name__=="__main__":

    count = 1
    fin = open(sys.argv[1])
    fin.readline()
    for line in fin:
        resolve(line, count, sys.stdout)
        count += 1
