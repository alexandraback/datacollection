import sys

def update_l(x, nums):
    l = []
    for i in range(len(nums)):
        if nums[i][0]:
            y = 1
            for j in range(len(nums)):
                if i != j and nums[j][0]:
                    if nums[i][1] == 0:
                        y = 1
                        break
                    s = abs(nums[i][1] - nums[j][1])/ x
                    y -= s
            
            if y < 0:
                #import pdb; pdb.set_trace()
                
                l.append((False,nums[i][1]))
            else:
                l.append((True,nums[i][1]))
        else:
            l.append(nums[i])
    c1 = len(list(x for b,x in nums if b))
    c2 = len(list(x for b,x in l if b))
    return c1 == c2,l

def case(idx, nums):
    #import pdb; pdb.set_trace()
    
    x = sum(nums)
    n = len(nums)
    l = [(True, z) for z in nums]
    while True:
        trx = sum(z for (b,z) in l if b)
        trx = trx if trx else x
        ret,l = update_l(trx, l)
        if ret:
            break
    
    rx = sum(x for (b,x) in l if b)
    rx = rx if rx else x

    rn = len(list(x for (b,x) in l if b))
    b = 2 * rx / rn
    

    result = []
    for bb,s in l:
        if bb:
            
            result.append((b-s)/rx)
        else:
            result.append(0.0)
    print "Case #%s: %s" % (idx, ' '.join(str (x*100)  for x in result))


lines = open('task1.in').readlines()[1:]
for i,line in enumerate(lines):
    nums = map(float, line.split()[1:])
    case(i + 1, nums)
