def solve(par):
    for i in xrange(len(par)):
        seen = [False]*1024
        seen[i] = True
        s = [i]
        while s:
            node = s.pop()
            for item in par[node]:
                if seen[item]:
                    return "Yes"
                else:
                    s.append(item)
                    seen[item] = True    
    return "No"

def validate(a): return int(a)-1

out = open("out.txt", "w")
count = 1
inp = open("small.in", "rU")
for line in xrange(int(inp.readline())):
    people = []
    for i in xrange(int(inp.readline())):
        people.append(map(validate, inp.readline().split())[1:])
    ans=solve(people)
    print "Case #%d: %s" % (count, ans)
    out.write("Case #%d: %s\n" % (count, ans))
    count += 1
out.close()
inp.close()
