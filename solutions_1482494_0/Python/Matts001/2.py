def solve(n, req):
    found=0
    turns=0
    while req:
        cur=found
        for item in req:
            if item[1] <= found:
                #we can get 2 stars
                found += 2 - item[2]
                turns += 1
                req.remove(item)

        if cur==found:#try with ones if we still haven't found anything
            high = req[0]
            for item in req:
                if item[0] <= found and (item[1] > high[1] or high[0] > found) and item[2] != 1:
                    #if valid, (better than current or current not valid), and hasn't been used before
                    high[:]=item
            if high[0] > found:#if no valid ones are found
                return "Too Bad"
            found += 1
            turns += 1
            req[req.index(high)][2] = 1
        
    return str(turns)

out = open("out.txt", "w")
inp = open('small.in', 'rU')
t=int(inp.readline())
count = 1

for zz in xrange(t):
    n=int(inp.readline())
    req=[]
    for i in xrange(n):
        req.append(map(int, inp.readline().split()) + [0])

    ans=solve(n, req)
    print "Case #%d: %s" % (count, ans)
    out.write("Case #%d: %s\n" % (count, ans))
    count += 1
out.close()
