from sympy.ntheory import factorint
from itertools import permutations as perm
import random
import multiprocessing
import time
from multiprocessing import Process, Manager







def isOk(s, seen):
    allb_d = []
    for base in xrange(2, 10+1):
        n= int(s, base)
        if base==2:
            if n in seen:
                return False
            seen[n] =True
        divisors = factorint(n)
        if len(divisors) == 1:
            return False
        #print divisors
        dvs =  divisors.items()[0][0]
        if n % dvs != 0:
            raise "ERR"
        allb_d.append(dvs )
    return allb_d

def proc(s,seen, items):
    print s
    divisors = isOk(s, seen)
    if divisors:
        items.append((s,divisors))
        #print l
        print "ds=",divisors, len(items)

def f(L, J):
    manager = Manager()
    seen = manager.dict()
    items = manager.list()

    B= [0]*L

    for w in xrange( L/3):
        B[w] = 1

    print B
    while len(items) < J:
        random.shuffle(B)
        A = B[:]
        A[0] = 1
        A[-1] =1
        s= "".join([str(x) for x in A])
        p = multiprocessing.Process(target=proc, args=( s,seen,items))
        p.start()
        p.join(1)
        if p.is_alive():
            print "kill"
            p.terminate()
            p.join()

    for s,ds in items:
        base = 2

        print s,
        for d in ds:
            print d,
        print
    return items

def save(fname,items):
    f = open(fname,'w')
    f.write( "Case #{0}: \n".format(1))
    for s,ds in items:
        f.write(s+" ")
        for d in ds:
            f.write(str(d) + " ")
        f.write("\n")
    f.close()

#items = f(6,3)
#save("solution_test", items)
items = f(16, 50)
save("solution_small", items)
#items = f(32, 500)
#save("solution_large", items)


