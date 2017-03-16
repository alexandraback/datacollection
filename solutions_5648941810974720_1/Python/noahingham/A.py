import math

def solve(n):
    count = {0:0,1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0}
    count[0]=n.count("Z")
    count[2]=n.count("W")
    count[4]=n.count("U")
    count[6]=n.count("X")
    count[8]=n.count("G")
    count[3]=n.count("H")-count[8]
    count[7]=n.count("S")-count[6]
    count[5]=n.count("V")-count[7]
    count[9]=n.count("I")-count[5]-count[6]-count[8]
    count[1]=n.count("N")-count[7]-2*count[9]
    string = ""
    for i in range(10):
        string+=str(i)*count[i]
    return string

if __name__ == "__main__":
	testcases = input()

	for caseNr in xrange(1, testcases+1):
		n = raw_input()
		print("Case #%i: %s" % (caseNr, solve(n)))
