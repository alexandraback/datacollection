def solver (tempdata):
	varlist = tempdata.split(" ")
	cookierate = 2
	c = float(varlist[0])
	f = float(varlist[1])
	x = float(varlist[2])
	time = 0
	cookiesdone = False

	while cookiesdone == False:
		if x/cookierate <= (c/cookierate+x/(cookierate+f)):		
			time = time + x/cookierate
			cookiesdone = True
		else:
			time = time + c/cookierate
			cookierate = cookierate + f
			
	return time
	
	
inputfile = open('B-large.in')
outputfile = open('B-large-done.txt', 'w')

numberofcases = inputfile.readline()     
for tempnumber in range(1, int(numberofcases)+1):
	tempdata = inputfile.readline().rstrip("\n")
	outputfile.write("Case #%i: %s\n" % (tempnumber, solver(tempdata)))
	
inputfile.close()
outputfile.close()