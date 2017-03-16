def factors(freespaces, dim):		#Returns P, Q, R such that P*Q+R = freespaces
	dim_factors = [dim, freespaces//dim, freespaces%dim]
	return dim_factors
	
def is_win(rows, cols, mines):
	maxdim = rows if rows > cols else cols
	mindim = cols if rows > cols else rows
	freespaces = rows*cols-mines
	out = [0, "", [0,0,0]]
	if (mindim == 2):
		if (freespaces%2==0):
			win = 1
			buildfactors = [2, freespaces//2, 0]
			case = "general-colsdim2" if mindim==cols else "general-rowsdim2"
			out = [win, case, buildfactors]
	else:
		out = check(rows, cols, freespaces)
		win = out[0]
		out[1] = out[1]+"-rows"
		if (win == 0):
			out = check(cols, rows, freespaces)
			win = out[0]
			out[1] = out[1]+"-cols"
	return out
	
def check(maxdim, mindim, freespaces):
	win = 0
	case = ""
	buildfactors = [0,0,0]
	for p in range(maxdim-1):
		maxrem = freespaces%(maxdim-p)
		maxwidth = freespaces//(maxdim-p)
		if (1 < maxwidth <= mindim and win == 0 and maxdim-p >= 2 and maxwidth >= 2):
			if (maxrem == 0):
				case = "general-rect"
				win = 1
				buildfactors = [maxdim-p, freespaces//(maxdim-p), freespaces%(maxdim-p)]
			elif (maxrem > 1):
				case = "general-rem"
				win = 1
				buildfactors = [maxdim-p, freespaces//(maxdim-p), freespaces%(maxdim-p)]
			elif (maxrem == 1):
				if (maxdim-p >= 4 and maxwidth >= 3):
					case = "general-onerem"
					win = 1
					buildfactors = [maxdim-p, freespaces//(maxdim-p), freespaces%(maxdim-p)]
	out = [win, case, buildfactors]
	return out
	
def buildminegrid(buildfactors, rows, cols, case):
	freespaces = buildfactors[0]*buildfactors[1]+buildfactors[2]
	mines = rows*cols - freespaces
	if case=="nomines":
		minegrid = ("."*cols+"\n")*(rows)
	elif case == "line":
		if rows==1:
			minegrid = "."*(freespaces)+"*"*mines+"\n"
		else:
			minegrid = ".\n"*(freespaces)+"*\n"*mines
	elif case == "onespace":
		minegrid = ("*"*cols+"\n")*(rows)
	elif case == "general-colsdim2":
		minegrid = "..\n"*(freespaces/2)+"**\n"*(mines/2)
	elif case == "general-rowsdim2":
		minegrid = ("."*(freespaces/2)+"*"*(mines/2)+"\n")*2
	elif case == "general-rect-cols":
		freecols = buildfactors[0]
		freerows = buildfactors[1]
		minegrid = ("."*freecols+"*"*(cols-freecols)+"\n")*freerows + ("*"*cols+"\n")*(rows-freerows)
	elif case == "general-rect-rows":
		freecols = buildfactors[1]
		freerows = buildfactors[0]
		minegrid = ("."*freecols+"*"*(cols-freecols)+"\n")*freerows + ("*"*cols+"\n")*(rows-freerows)
	elif case == "general-rem-cols":
		freecols = buildfactors[0]
		freerows = buildfactors[1]
		rem = buildfactors[2]
		minegrid = ("."*freecols+"*"*(cols-freecols)+"\n")*freerows + "."*rem+"*"*(cols-rem)+"\n"+("*"*cols+"\n")*(rows-freerows-1)
	elif case == "general-rem-rows":
		freecols = buildfactors[1]
		freerows = buildfactors[0]
		rem = buildfactors[2]
		minegrid = ("."*(freecols+1)+"*"*(cols-freecols-1)+"\n")*rem +("."*freecols+"*"*(cols-freecols)+"\n")*(freerows-rem)+("*"*cols+"\n")*(rows-freerows)
	elif case == "general-onerem-cols":
		freecols = buildfactors[0]
		freerows = buildfactors[1]
		rem = buildfactors[2]+1
		onerempos = freerows
		minegrid = ("."*freecols+"*"*(cols-freecols)+"\n")*freerows + "."*rem+"*"*(cols-rem)+"\n"+("*"*cols+"\n")*(rows-freerows-1)
		minegrid = minegrid[:freerows*(cols+1)-2]+"*"+minegrid[freerows*(cols+1)-1:]
	elif case == "general-onerem-rows":
		freecols = buildfactors[1]
		freerows = buildfactors[0]
		rem = buildfactors[2]+1
		minegrid = ("."*(freecols+1)+"*"*(cols-freecols-1)+"\n")*rem +("."*freecols+"*"*(cols-freecols)+"\n")*(freerows-rem)+("\n"+"*"*cols+"\n")*(rows-freerows)
		onerempos = freecols-1
		minegrid = minegrid[:(rows-1)*(cols+1)+onerempos]+"*"+minegrid[(rows-1)*(cols+1)+onerempos+1:]
	else:
		print "fuck"
	#minegrid = case+"\nc"+minegrid[1:]
	minegrid = "c"+minegrid[1:]
	return minegrid

lines = [line.rstrip('\n') for line in open("C-large.in")] 
outputfile = open("output.txt", 'w')
for i in range(1,int(lines[0])+1):	#number of test cases
	params = lines[i].split()
	rows = int(params[0])
	cols = int(params[1])
	mines = int(params[2])
	mindim = rows if (rows < cols) else cols
	maxdim = cols if (rows < cols) else rows
	area = rows*cols
	freespaces = rows*cols-mines
	listfactors = []
	#Impossible or free cases
	win = 0
	if (mines == 0):
		win = 1
		case = "nomines"
		factors = [0,0,0]
	elif (mindim == 1):
		win = 1
		case = "line"
		buildfactors = [mindim, freespaces//mindim, freespaces%mindim]
	elif (freespaces == 1):
		win = 1
		case = "onespace"
		buildfactors = [0,0,0]
	elif (freespaces == 2 or freespaces == 3):
		win = 0
	else:
		out = is_win(rows, cols, mines)
		win = out[0]
		buildfactors = out[2]
		case = out[1]
	if (win == 0):
		newline = "Case #"+str(i)+":\nImpossible\n"		
	if (win == 1):
		#newline = "Case #"+str(i)+": "+lines[i]+"\n"+buildminegrid(buildfactors, rows, cols, case)
		newline = "Case #"+str(i)+":\n"+buildminegrid(buildfactors, rows, cols, case)
	outputfile.write(newline)
outputfile.close()

	