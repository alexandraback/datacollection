t = int(raw_input())

for i in xrange(1, t + 1):
    S = raw_input()
    output = S[0:1]
    
    for j in xrange(1, len(S)):
        if S[j] >= output[0]:
            output = S[j] + output
        else:
            output = output + S[j]
    
    print "Case #{}: {}".format(i, output)
