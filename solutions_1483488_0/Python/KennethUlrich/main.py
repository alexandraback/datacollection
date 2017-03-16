import sys

sys.stdin.readline()

for tc, line in enumerate(sys.stdin):
    v = [int(n) for n in line.strip().split()]
    a, b = v
    result = 0
    for i in range(a, b + 1):
        s = str(i)
        recycled = set()
        for j in range(1, len(s)):
            candidate = s[j:] + s[:j]
            if not candidate.startswith("0") and int(candidate) > i and int(candidate) <= b:
                recycled.add(candidate)
        result += len(recycled)  
    print "Case #%d: %d" % (tc + 1, result)
            
    
    
    