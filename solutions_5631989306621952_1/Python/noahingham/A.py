import math

def solve(str):
    r = ""
    for s in str:
        r = first(s,r)
    return r

def first(letter,string):
    if(string==""):
        return letter
    first = string[0]
    if(ord(letter)>=ord(first)):
        return letter+string
    return string+letter

if __name__ == "__main__":
	testcases = input()

	for caseNr in xrange(1, testcases+1):
		n = raw_input()
		print("Case #%i: %s" % (caseNr, solve(n)))
