#MAM, Google Code Jam - Round 1C, Problem 1 - Battleship

def solve(c):
	R, C, W = [int(x) for x in c.rstrip().split()]
	guesses = C/W
	if C%W: guesses = guesses + 1
	return (R*guesses)+(W-1)

def main():
	with open('A-small-attempt2.in', 'r') as infile, open('output.txt', 'w') as outfile:
		
		T = int(infile.readline())
		for x in xrange(T):
			line = infile.readline()
			outfile.write("Case #" + str(x + 1) + ": " + str(solve(line)) + "\n")

if __name__ == "__main__":
	main()