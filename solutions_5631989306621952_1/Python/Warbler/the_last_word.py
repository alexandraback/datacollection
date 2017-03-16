
def solve(word):
    lenth=len(word)
    rslt=word[0]
    for i in range(1,lenth):
        if word[i]>=rslt[0]:
            rslt=word[i]+rslt
        else:
            rslt=rslt+word[i]
    return rslt

testcases = input()
for caseNr in xrange(1, testcases+1):
    word = raw_input()
    print("Case #%s: %s" % (caseNr, solve(word)))

