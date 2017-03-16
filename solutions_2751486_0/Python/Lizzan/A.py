"""Code written using Python 2.7.2, http://www.python.org/"""
import re

def calc(case):
	(name, n) = case.split()
	#n = int(n)
	#print name, n

	pattern = re.compile(r"[^aeiou]{"+n+"}")

	count = 0
	for i in range(0, len(name)+1):
		for j in range(i, len(name)+1):
			#print 'Checking ', name[i:j]
			if pattern.search(name,i,j):
				count = count + 1
				#print 'Match'


	return count
	
		
		

f = open('A-small.in', 'r')
lines = f.readlines()
f.close()
c = lines[0].split()[0]
#print c
cases = [r.strip() for r in lines[1:]]
#print cases

of = open('output_a_small.txt', 'w')

for idx, case in enumerate(cases):
	of.write('Case #%(idx)i: %(i)i\n' % {'idx': idx + 1, 'i': calc(case)})

of.close()
