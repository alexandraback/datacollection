

def process(name,n):
	length = len(name)
	total = 0;
	for rnge in range(n,length+1):
		for start in range(length-rnge+1):
			if contains(name[start:start+rnge],n):
				total += 1
	return total

def contains(sub,n):
	counter = 0
	for i in range(len(sub)):
		if not (sub[i] in vowels):
			counter += 1
			if (counter == n):
				return True		
		else: 
			counter = 0
	return False

# def process()
vowels = ['a','e','i','o','u']
letters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
lines = [line.strip() for line in open('../Input/A-small.in')]
output = open('../Output/A.txt', 'w')

L = int(lines[0]);
counter = 1
for i in range(L):
	[name, n] = lines[counter].split()
	n = int(n)
	case = "Case #" + str(i+1) + ": " + str(process(name,n)) + "\n"
	print case
	output.write(case)

	counter += 1