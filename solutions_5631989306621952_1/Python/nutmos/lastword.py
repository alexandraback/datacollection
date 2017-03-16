N = int(raw_input())
for I in range(1,N+1):
    s = raw_input()
    result = ""
    for c in s:
        if len(result) == 0:
            result = result + str(c)
        else:
            if (result[0] <= c):
                result = str(c) + result
            else:
                result = result + str(c)
    print "Case #" + str(I) + ": " + result
