def solve(info):
    s=list(info)
    w=s[0]
    s.pop(0)
    for l in s:
    	if w[0]>l:
    		w=w+l
    	else:
    		w=l+w
    return w

if __name__ == "__main__":
    testcases = input()
    for caseNr in xrange(1, testcases + 1):
        info = raw_input()
        print("Case #%i: %s" % (caseNr, solve(info)))
