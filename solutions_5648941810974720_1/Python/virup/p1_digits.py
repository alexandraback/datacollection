import sys
import time

first = {'Z':('ZERO',0), 'W':('TWO',2),'U':('FOUR',4),'X':('SIX',6),'G':('EIGHT',8)}
second = {'F':('FIVE',5), 'H':('THREE',3), 'S':('SEVEN',7)}
third = {'O':('ONE',1), 'I':('NINE',9)}
decoder = [first, second, third]

def solve_digits(s):
	freq = {}
	for c in s:
		freq[c] = freq.get(c,0) + 1
	output = ''
	for level in decoder:
		for (key,value) in level.items():
			count = freq.get(key,0)
			if count > 0:
				output += str(value[1])*count
				for c in value[0]:
					freq[c] -= count
	output = ''.join(sorted(output))
	return output

def main():
	start_time = time.time()
	input_file = sys.argv[1]
	with open(input_file, 'r') as f:
		lines = f.readlines()

	for i in range(1,len(lines)):
		print "Case #%d: " % i + solve_digits(lines[i])
	
	# print "Time (seconds):", time.time()-start_time

if __name__ == "__main__":
	main()

