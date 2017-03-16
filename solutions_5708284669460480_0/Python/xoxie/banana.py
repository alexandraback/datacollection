#brute force o_O
import sys
import itertools as it

f = open( sys.argv[1] )
f.readline()

t = 1
l = f.readline()
while l != "":
    k,l,s = [int(x) for x in l.split()]
    keys = f.readline().strip()
    target = f.readline().strip()

    counts = {} #number of combis that make this
    nums = {}

    invalid = 0
    for x in target:
        if x not in keys:
            invalid = 1
            break

    if not invalid:
        combis = it.product(keys,repeat=s)
    else:
        combis = []

    for x in combis:
        num = 0
        x = "".join(x)
        if x in counts:
            counts[x] += 1
            continue
        else:
            counts[x] = 1
        i = 0
        while i < len(x):
            try:
                i = x.index(target,i)
                num += 1
            except ValueError:
                break
            i += 1
        nums[x] = num
    
    output = 0
    if len(counts) > 0:
        total = 0
        for x in counts:
            total += counts[x] * nums[x]
        total = total * 1.0 / (k**s)

        output = max(nums.values())*1.0 - total

    print "Case #{}: {}".format(t,output)
    t += 1
    l = f.readline()
