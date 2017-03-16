def solve(a, b, line):
    chances = [line[0]]
    for i in xrange(1, len(line)):
        chances.append((chances[i-1]) * line[i])
    
    #keep typing
    keep = ((b-a+1) * chances[-1]) + ((2*b-a+2)*(1-chances[-1]))
    #press enter
    re = (2+b)
    #backspace x chars
    back = []
    for i in xrange(a):
        back.append(((i*2+b-a+1) * chances[a-i-1]+1) + ((2*i+2*b-a+2)*(1-chances[a-i-1]))-1)
        #print i
    return min(back + [re])



out = open("out.txt", "w")
count = 1
for line in open("large.in", "rU").readlines()[1:]:
    if count % 2:#if first line
        a, b = map(int, line.split())
    else:
        line = map(float, line.split())
        ans=solve(a, b, line)
        print "Case #%d: %.6f" % (count/2, ans)
        out.write("Case #%d: %.6f\n" % (count/2, ans))
    count += 1
out.close()
