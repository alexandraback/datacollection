import os, sys, math
from operator import itemgetter, attrgetter

def palindrome(num):
	num = str(num)
	for x in xrange(0, int(math.floor(len(num)/2))):
		if num[x] != num[len(num)-x-1]:
			return False
	return True


try:
	file = sys.argv[1]
except Exception as inst:
	print inst, '\n\nSyota avattava tiedosto parametrina!\n\n'
finally:
	file = sys.argv[1]
	fin = open(file, 'r')
	fout = open(file[:-2]+'out', 'w')
	cases = fin.readline()
	print 'tapauksia ' + cases

	#Brute force all the numbers matching the crietria
	lista = []
	for a in xrange(1, int(math.ceil(math.sqrt(pow(10,15))))):
		if palindrome(a):
			b = a*a
			if palindrome(b):
				#print a, b
				lista.append(b)
	'''
	for l in lista:
		print l
	'''
	
	for case in range(0, int(cases)):
	#for case in range(0, 1):

		size = map(int, fin.readline()[:-1].split(' '))
		print 'Alue: ', size

		count = 0
		for x in lista:
			if x >= size[0] and x <= size[1]:
				count +=1

		print ('Case #'+str(case+1)+': '+ str(count) +'\n')
		fout.write('Case #'+str(case+1)+': '+ str(count) +'\n')


		
	fin.close()
	fout.close()
