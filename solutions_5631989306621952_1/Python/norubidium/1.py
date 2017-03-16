n = int(raw_input())
for i in xrange(n):
    line = raw_input()
    result = ""
    for c in line:
        if len(result) == 0:
            result = c
        elif c >= result[0]:
            result = c + result
        else:
            result += c
    print "Case #"+str(i+1) + ": " + result
