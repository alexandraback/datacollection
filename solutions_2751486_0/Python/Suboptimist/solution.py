import lib
from sets import Set


@lib.wrapper
def solution(input, output):
	vowels = ['a', 'e','i','o','u']
	T = input.int()
	for case in xrange(T):
		data = input.str().split()
		name = data[0]
		n = int(data[1])
		substrings = Set()
		in_consonants = False
		start = -1
		for i in xrange(len(name)+1):
			if (i==len(name) or name[i] in vowels) and in_consonants is True:
				length = i-start
				if length>=n:
					for j in xrange(length-n+1):
						for k in xrange(0,start+j+1):
							for l in xrange(start+j+n-1,len(name)):
								substrings.add((k,l))
				in_consonants = False
			elif i<len(name) and name[i] not in vowels and in_consonants is False:
				start = i
				in_consonants = True
		output.result(case+1, len(substrings))
		
if __name__ == '__main__':
	solution()
