'''
Created on 05 May 2012

@author: dirk-b
'''

inp = open('data/A-small-attempt3.in', 'r')
out = open('data/A-small-attempt3.out', 'w')

T = int(inp.readline())

for t in xrange(1, T + 1):
    nums = map(int, inp.readline().split())
    N = nums[0]
    scores = nums[1:]
    X = sum(scores)
    
    # find aim here
    aim = 0.0
    
    ss = [x for x in scores]
    ss.sort()
    
    used = 0
    
    ans = []
    for i, l in enumerate(ss[:-1]):
        willUse = (ss[i + 1] - l) * (i + 1)
        if willUse + used > X:
            aim = ss[i] + (X - used + 0.0) / (i + 1)
            used = X  
            break
        used += willUse
        aim = ss[i + 1] + 0.0
    
    
    #print 'u', used
    
    left = X - used
    aim += left / N
    
    #print 'a', aim
    
    for sc in scores:
        if sc >= aim:
            ans.append(0)
        else:
            ans.append((aim - sc) / X)
    
    # any leftover points distribute evenly
        
        
    
    
    
    
    
    out.write("Case #%d:" % t)
    for a in ans:
        out.write(" %.6f" % (a * 100))
    out.write("\n")

inp.close()
out.close()
    
