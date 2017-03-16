f = open("A-small-attempt0.in")
fo = open("output.txt",'w')

con = 'bcdfghjklmnpqrstvwxyz'
vow = 'aeiou'

def isallcon(string):
	global con
	for letter in string:
		if letter in 'aeiou':
			return False
	return True

case_num = int(f.readline().strip())
for i in range(0,case_num):
	string, n = f.readline().strip().split()
	n = int(n)
	n_val = 0
	sub = {}
	for j in range(0, len(string)-n +1):
		sub_str = string[j:j+n]
		if isallcon(sub_str):
			for b in range(0, j+1):
				for e in range(j+n-1, len(string)):
					sub[(b,e)] = sub.get((b,e), 1)

	fo.write("Case #" + str(i+1) + ": " + str(len(sub)) + "\n")

f.close()
fo.close()