import sys

def main():
	fp = open('B-large.in', 'r')
	fp.readline()

	n = 1
	for line in fp.readlines():
		result = 0
		line = [int(x) for x in line.strip().split(' ')]
		#print line
		
		for x in line[3:]:
			'''
			menor = (x - 2) / 3
			#print x, menor, line[2], line[1], menor + 1 >= line[2]
			if menor + 1 >= line[2]:
				result += 1
			if menor + 2 >= line[2] and line[1] > 0:
				line[1] -= 1
				result += 1
			'''
			
			if x == 0:
				if line[2] <= 0:
					result += 1
			elif x == 1:
				if line[2] <= 1:
					result += 1
			
			elif (x % 3) == 0:
				if x / 3 >= line[2]:
					result += 1
				elif x / 3 + 1 >= line[2] and line[1] > 0:
					result += 1
					line[1] -= 1
			
			elif (x % 3) == 1:
				if x / 3 + 1 >= line[2]:
					result += 1
			
			elif (x % 3) == 2:
				if x / 3 + 1 >= line[2]:
					result += 1
				elif x / 3 + 2 >= line[2] and line[1] > 0:
					result += 1
					line[1] -= 1
		
		sys.stdout.write("Case #" + str(n) + ": " + str(result) + "\n")
		n+=1

if __name__ == "__main__":
	main()

