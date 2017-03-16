import os, sys
from operator import itemgetter, attrgetter

def isWinner(li):
	win = True
	if li[0] == 'T':
		li[0] = li[1]
	if li[0] == '.':
		win = False
	else:
		for x in xrange(1,4):
			if li[x] == '.':
				win = False
				break
			if li[0] != li[x] and li[x] != 'T':
				win = False
				break
	if win:
		return li[0]
	else:
		return win


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
		line = []
		for x in xrange(0,4):
			line.append(fin.readline())
		print line
		#print line[0][0], line[2][2]

		#print isWinner(['T','O','X','X'])
		#print isWinner([line[0][0],line[0][1],line[0][2],line[0][3]])
		win = False

		#check hor and ver lines
		for x in xrange(0,4):
			win = isWinner([line[x][0],line[x][1],line[x][2],line[x][3]])
			if win:
				break
			win = isWinner([line[0][x],line[1][x],line[2][x],line[3][x]])
			if win:
				break

		# check cross lines
		if not win:
			win = isWinner([line[0][0],line[1][1],line[2][2],line[3][3]])
		if  not win:
			win = isWinner([line[0][3],line[1][2],line[2][1],line[3][0]])


		if win:
			print ('Case #'+str(case+1)+': '+ str(win) + ' won\n')
			fout.write('Case #'+str(case+1)+': '+ str(win) + ' won\n')
		else:
			end = True
			for x in xrange(0,4):
				for y in xrange(0,4):
					#print line[x][y], x, y
					if line[x][y] == '.':
						end = False
						break
						break
			if not end:
				print ('Case #'+str(case+1)+': Game has not completed\n')
				fout.write('Case #'+str(case+1)+': Game has not completed\n')
			else:
				print ('Case #'+str(case+1)+': Draw\n')
				fout.write('Case #'+str(case+1)+': Draw\n')
		fin.readline()

		
	fin.close()
	fout.close()
