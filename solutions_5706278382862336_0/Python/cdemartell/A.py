def solve (input):
	numbers = [int(integer) for integer in input.split("/")]
	p = numbers[0]
	q = numbers[1]
	d=gcd(p,q)
	p = p//d
	q = q//d
	c=0	
	
	if ((q & (q - 1)) != 0):
		output="impossible"
	else:
		output = iterator(p,q,c)
	return output

def gcd (a,b):
	while b!=0:
		(a,b) = (b, a%b)
	return a
	
def iterator (p,q,c):
	if (p/q >= 0.5):
		return c+1
	else:
		return iterator(p,q//2,c+1)
	
inputfile = open('A-small-attempt0.in')
outputfile = open('A-small-attempt0-done.txt', 'w')

numberofcases = inputfile.readline()     
for cases in range(1, int(numberofcases)+1):
	input = inputfile.readline().rstrip("\n")
	outputfile.write("Case #%i: %s\n" % (cases, solve(input)))