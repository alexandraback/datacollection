"""
GCJ 2013
url http://code.google.com/codejam/contest/2270488/dashboard#s=p2
"""
import sys

def palindromes():
	"""A palindrome generator"""
	i = 1
	s = '1'
	l = 1
	queue = []
	while True:
		while l == len(s):
			a,b = makePalindrome(s)
			yield int(b)
			queue.append(a)
			i += 1
			s = str(i)
		while queue:
			yield int(queue.pop(0))
		l += 1

def makePalindrome(s):
	s2 = list(s)
	s2.reverse()
	return(''.join([s]+s2), ''.join([s]+s2[1:]))


def isPalindrome(s):
	"""checks that a string is a palindromes"""
	for i in range(len(s)//2):
		if s[i] != s[-i-1]:
			return False
	return True

def fairNsquare():
	""" a fair and square generator """
	gen = palindromes()
	while True:
		i = next(gen)
		if isPalindrome(str(i*i)):
			yield i*i

def call(f, min, max):
	"""generator that gives values of a generator between min and max """
	gen = f()
	i = next(gen)
	while i < min:
		i = next(gen)
	while i <= max:
		yield i
		i = next(gen)

def values(l, min, max):
	"""function that gives the number of values of a list between min and max """
	res = 0
	gen = iter(l)
	i = next(gen)
	while i < min:
		i = next(gen)
	while i <= max:
		res += 1
		i = next(gen)
	return res

def process(f, output):
    nb_of_cases = int(f.readline().rstrip())
    FN = [i for i in call(fairNsquare, 1, 10**15)]
    print(FN)
    for n in range(1, nb_of_cases + 1):
        print('Case', n)

        A, B = (int(i) for i in f.readline().rstrip().split())

       	answer = values(FN, A, B)
        print('Answer:', answer)
        output.write('Case #{0}: {1}\n'.format(n, answer))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("missing argument input_file")
        sys.exit(2)
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[1] + '.out', 'w+')
    process(input_file, output_file)


