#!/usr/bin/python
import sys

def skip(n):
    # skip 2222,3333, 44, etc.
    ones = 0
    for i in xrange(len(str(n))):
        ones = ones *10 + 1
    if n%ones == 0: return True
    return False

def gen_pair(strA,strB):
    s = set([])
    count=0
    n = len(strA)
    for i in xrange(1, n):
        if strA[i] != '0':
            strA_ = strA[i:]+strA[:i]
            if strA_>strA and int(strA_) <= int(strB):
                #print strA,strA_
                key = strA+':'+strA_
                if key in s:
                    #print key
                    continue
                s.add(key)
                count += 1
    return count            

def process(strA,strB):
    intA = int(strA)
    intB = int(strB)
    count=0
    for i in xrange(intA,intB):
        if skip(i): continue
        count+=gen_pair(str(i), strB)
    #print count
    return count

def main():
    #process(100,500)

    #sys.exit(0)

    T = int(sys.stdin.readline().strip())
    x = 1
    while x <= T:
        instr = sys.stdin.readline().strip().split(' ')
        A = instr[0]
        B = instr[1]
        
        print "Case #%d: %d" %(x, process(A, B))
        x += 1
    return

main()
