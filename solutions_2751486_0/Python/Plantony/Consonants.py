#!C:\Python33\python
import sys
import fileinput
import string

sys.path.append(r'D:\Data\Programming\Code Jam\Libraries')
from CodeJamLib import *

def main ():
	lines = fileinput.input()
	cases = int(lines.readline())
	for case in range(1, cases + 1):
		parts = lines.readline().split(" ")
		print ("Case #{0}: {1}".format(case, getValue(parts[0], int(parts[1]))))

def getValue (name, n):
	count = 0
	for start in range(len(name)):
		for size in range(1, len(name) + 1 - start):
			if getConsecutiveConsonants (name[start:start + size]) >= n:
				count += 1
	
	return count

def getConsecutiveConsonants(name):
	consecutive = 0
	largest = 0
	consonants = [c for c in string.ascii_lowercase + string.ascii_uppercase if c not in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']]
	for c in name:
		if c in consonants:
			consecutive += 1
			if consecutive > largest:
				largest = consecutive
			
		else:
			consecutive = 0
	
	return largest
	
main()