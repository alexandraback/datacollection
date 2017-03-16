lines = [line.rstrip('\n') for line in open("B-small-attempt1.in")] 
outputfile = open("output2.txt", 'w')
print int(lines[0])+1
for i in range(1,int(lines[0])+1):	#number of test cases
	time = 0
	parameters = lines[i].split()
	farmcost = float(parameters[0])
	farmincome = float(parameters[1])
	winningscore = float(parameters[2])
	#print "Farm Cost: " + str(farmcost)+"\nFarm Inc:  "+str(farmincome)+"\nWin. Score: "+str(winningscore)
	time_nofarm = 0.0
	time_farm = 0.0
	time_buildnewfarm = 0.0
	time_buildcurfarms = 0.0
	numfarms = 0.0
	while (time_nofarm >= time_farm):
		income = 2.0+farmincome*numfarms
		time_buildnewfarm = farmcost/income
		time_nofarm = time_buildcurfarms + winningscore/income
		time_farm = time_buildcurfarms + time_buildnewfarm + winningscore/(income+farmincome)
		#print "time_nofarm: "+str(time_nofarm)
		#print "time_farm  : "+str(time_farm)
		#print "time_buildcurfarms:"+str(time_buildcurfarms)
		#print "time_buildnewfarm :"+str(time_buildnewfarm)
		if time_farm <= time_nofarm:
			numfarms = numfarms + 1
			time_buildcurfarms = time_buildcurfarms+time_buildnewfarm
	time = time_nofarm
	newline = "Case #"+str(i)+": "+str(time)+"\n"
	outputfile.write(newline)
outputfile.close()
