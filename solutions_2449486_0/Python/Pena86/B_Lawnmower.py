import os, sys
from operator import itemgetter, attrgetter



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
	
	for case in range(0, int(cases)):
	#for case in range(0, 3):

		size = map(int, fin.readline()[:-1].split(' '))
		print 'Koko: ', size


		lawn = []
		#cut = []
		for x in xrange(0, size[0]):
			#lawn.append(map(int, fin.readline()[:-1].split(' ')))
			#if the input has no empty line at last
			rivi = fin.readline()
			if rivi[len(rivi)-1] == '\n':
				rivi = rivi[:-1]
			lawn.append(map(int, rivi.split(' ')))
			#
			#cut.append([False] *size[1])
		longY = [0] *size[1]
		for y in xrange(0, size[1]):
			for x in xrange(0, size[0]):
				if longY[y] < lawn[x][y]:
					longY[y] = lawn[x][y]
		#print longY
		possible = True

		#print lawn
		#print cut
		for x in xrange(0, size[0]):
			for y in xrange(0, size[1]):
				if lawn[x][y] == max(lawn[x]) or lawn[x][y] == longY[y]:
					pass
					#cut[x][y] = True
				else:
					possible = False
					break
					break
		#print cut
		if possible:
			print ('Case #'+str(case+1)+': YES\n')
			fout.write('Case #'+str(case+1)+': YES\n')
		else:
			print ('Case #'+str(case+1)+': NO\n')
			fout.write('Case #'+str(case+1)+': NO\n')




		
	fin.close()
	fout.close()
