#!/usr/bin/python
import sys

f_input = open(sys.argv[1])
#problems = int(f_input.readline().rstrip())

VOWELS = ("a", "e", "i", "o", "u")
def solve(name, n):
    ret, vowcount, untilcount = 0,0,0
    for i in xrange(len(name)):
        #print untilcount, vowcount
        untilcount += 1
        
        if not name[i] in VOWELS:
            vowcount+=1
            if vowcount == n:
                ## until * rest ##
                ret += (untilcount-n+1) * (len(name) - i)
                #print "vowsum:",(untilcount-n+1), (len(name)-i)
                vowcount = n-1
                untilcount = n-1
        else:
            vowcount = 0
    return ret
            
linenums = int(f_input.readline().rstrip())
for i in xrange(linenums):
    name, n_str = f_input.readline().rstrip().split(" ")
    ans = solve(name, int(n_str))
    sys.stdout.write("Case #"+str(i+1)+": "+str(ans)+"\n")


