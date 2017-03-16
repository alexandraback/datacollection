#MAM, Google Code Jam - 2016 Round 1B, Problem 1
#Geting the Digits

def shortenStr(orig, remove, times):
	#print "shortening ", remove, times
	for each in remove:
		orig = ''.join(orig.split(each, times))
	return orig

def findAndRemove(orig, letter, spelled, answer, number):
	temp = orig.count(letter)
	orig = shortenStr(orig, spelled, temp)
	answer = answer + number * temp
	return orig, answer

def solve(c):

	letters = c.upper() + ""
	answer = ""

	#remove in the below order; evens need only the characters, 1 needs 0,2,4; 3 needs 8; 5 needs F; 7 needs 6; 9 needs 5,6,8
	#z, 0; w, 2; u, 4; x, 6; g, 8; o, 1; h, 3; f, 5; s, 7; i, 9

	letters, answer = findAndRemove(letters, 'Z', "ZERO", answer, '0')
	letters, answer = findAndRemove(letters, 'W', "TWO", answer, '2')
	letters, answer = findAndRemove(letters, 'U', "FOUR", answer, '4')
	letters, answer = findAndRemove(letters, 'X', "SIX", answer, '6')
	letters, answer = findAndRemove(letters, 'G', "EIGHT", answer, '8')
	letters, answer = findAndRemove(letters, 'O', "ONE", answer, '1')
	letters, answer = findAndRemove(letters, 'H', "THREE", answer, '3')
	letters, answer = findAndRemove(letters, 'F', "FIVE", answer, '5')
	letters, answer = findAndRemove(letters, 'S', "SEVEN", answer, '7')
	letters, answer = findAndRemove(letters, 'I', "NINE", answer, '9')

	return ''.join(sorted(answer))

def main():
	with open('A-small-attempt0.in', 'r') as infile, open('output.txt', 'w') as outfile:
		
		T = int(infile.readline())
		for x in xrange(T):
			line = infile.readline().rstrip()
			outfile.write("Case #" + str(x + 1) + ": " + str(solve(line)) + "\n")

if __name__ == "__main__":
	main()