n = int(raw_input())
for case in xrange(1,n+1):

    word = raw_input()
    res = ""
    for letter in word:
        if len(res)==0 or letter < res[0]:
            res += letter
        else:
            res = letter + res

    print "Case #%d: %s" % (case, res)
    
