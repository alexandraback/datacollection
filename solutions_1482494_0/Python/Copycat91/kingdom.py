import sys, traceback

def evalEachCase (ai, bi):
	DONE = -999999
	HIGHEST = 999999
	stars = 0
	
	steps = 0
	while stars < 2*len(ai):
		# memilih level mana yang akan dijalankan
		# maxp adalah priority tertinggi
		maxp = -1
		toDos = []
		for i in range(len(ai)):
			a = ai[i] - stars
			b = bi[i] - stars
			
			# menghitung prioritas
			if (DONE < a <= 0 and b > 0):
				p = b
			elif (DONE < a <= 0 and DONE < b <= 0):
				p = HIGHEST
			elif (a <= DONE and DONE < b <= 0):
				p = HIGHEST - 1
			else:
				p = -1
			
			# membandingkan prioritas
			if (p > maxp):
				maxp = p
				toDos = [i]
			elif (p == maxp and p >= HIGHEST - 1):
				toDos.append(i)
		
		# jika ada yang dapat dikerjakan
		if maxp > -1:
			steps += len(toDos)
			if maxp < HIGHEST - 1: # kerjakan bintang 1 saja
				stars += len(toDos)
				for toDo in toDos: ai[toDo] = DONE
			elif maxp == HIGHEST: # kerjakan langsung bintang 2
				stars += 2*len(toDos)
				for toDo in toDos:
					ai[toDo] = DONE
					bi[toDo] = DONE
			else: # kerjakan bintang 2 stlh bintang 1
				stars += len(toDos)
				for toDo in toDos: bi[toDo] = DONE
		
		# jika tidak ada yang dapat dikerjakan
		else:
			return "Too Bad"
		
		if (stars > len(ai)*2): print "asdf"
	
	return str(steps)

def main ():
	dir = "C:/Users/Firman/Documents/Programming/Python/GoogleCodeJam/2012/Round1A/"
	fin = open (dir+"B-small-attempt0.in", "r") # nama file input
	fout = open (dir+"B-small-attempt0.out", "w") # nama file output
	
	content = fin.read()
	lines = content.split('\n')
	
	T = eval(lines.pop(0))
	
	linesOut = []
	for i in range (T):
		N = eval(lines.pop(0))
		ai = []
		bi = []
		for j in range(N):
			args = lines.pop(0).split()
			ai.append(eval(args.pop(0)))
			bi.append(eval(args.pop(0)))
		print "Attempting Case #" + str(i+1)
		linesOut.append ("Case #" + str(i+1) + ": " + evalEachCase (ai, bi) )
	
	contentOut = "\n".join(linesOut)
	fout.write(contentOut)
	
	fin.close()
	fout.close()

try:
	main()
	print "Success"
	raw_input()
except:
	exc_type, exc_value, exc_traceback = sys.exc_info()
	print traceback.print_tb(exc_traceback)
	print traceback.print_exception(exc_type, exc_value, exc_traceback)
	raw_input()
