#inefficient =(
import sys
import itertools as it

f = open(sys.argv[1])
f.readline()
t = 1
l = f.readline()
while l != "":
    maxc,d,maxv = [int(x) for x in l.split()]
    d = [int(x) for x in f.readline().split()]
    output = 0

    d.sort()

    v = set(range(1,maxv+1))
    newd = set(range(1,maxv+1))-set(d)

    #all values that can be made already
    existingv = set([0])
    for i in range(1,len(d)+1):
        combis = it.combinations(d,i)
        for j in combis:
            existingv.add(sum(j))

    # v is new values that need to be made up
    v -= existingv

    #print "denoms ", d
    #print "existing values ", existingv
    #print "values to make up ", v

    while len(v) > 0:
        z = min(v)
        newd.remove(z)

        newvalues = set([x+z for x in existingv])
        existingv = existingv | newvalues
        v -= newvalues

        output += 1
        #print "existing values ", existingv
        #print "values to make up ", v


    #print "need to make ",v
    #print "already have ",d
    #print "choose from ",newd

    print "Case #{}: {}".format(t,output)
    t += 1
    l = f.readline()

    
