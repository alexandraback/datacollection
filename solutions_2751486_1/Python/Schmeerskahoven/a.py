import sys

t = int(sys.stdin.readline())

def is_vowel(a):
	return a in {'a','e','i','o','u'}

def solve():
	name, nword = sys.stdin.readline().split()
	n = int(nword)
	positions = []
	current = -1
	start = 0
	for i,a in enumerate(name+'a'):
		if current == -1 and not is_vowel(a):
			#print (a, ' @ ', i)
			current = i
			start = i
		elif current != -1:
			if not is_vowel(a):
				#print (a, ' ', i - start)
				if i - start == n:
					positions.append((start,i))
					start = start + 1
				current = i
			else:
				if i - start == n:
					positions.append((start, i))
				current = -1
	#print (positions)
	acc = 0
	for i, (start, end) in enumerate(positions):
		if i != 0:
			start = start - positions[i-1][0] - 1
		acc += (start + 1) * (len(name)-(end-1))
	return acc
for ASDF in range(1,t+1):
	print ("Case #%d: %d" % (ASDF, solve()))
