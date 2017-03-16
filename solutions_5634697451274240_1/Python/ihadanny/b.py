import sys

def coalesce(s):
    r = s[0]
    for i in range(1, len(s)):
        if s[i]!=r[-1]:
            r += s[i]
    return r

cache = {}

def flip(s):
    r = ""
    for c in s[::-1]:
        r += "-" if c == "+" else "+"
    return r
        
def count_flips(s, depth):
    s = coalesce(s)
    #print depth*"*", s
    if len(s) == 1:
        if s == "+":
            return [0, 1]
        else:
            return [1, 0]
    if s in cache:
        return cache[s]
        
    cache[s] = [1000000, 1000000]
    min_flips = cache[s]
    for i in range(1, len(s)+1):
        new_s = flip(s[:i]) + s[i:]
        flips = count_flips(new_s, depth+1)
        #print depth*"*", i, new_s, flips
        for j in [0,1]:
            min_flips[j] = min(min_flips[j], flips[j]+1)
        #print depth*"*", i, "min_flips", min_flips
    cache[s] = min_flips
    #print "cache ", s, min_flips
    return min_flips
        
T = int(sys.stdin.readline())
case = 1
for line in sys.stdin:
    s = line.strip()
    if len(s) > 0:
        cache = {}
        print "Case #{0}:".format(case), count_flips(s, 1)[0]
        case += 1


