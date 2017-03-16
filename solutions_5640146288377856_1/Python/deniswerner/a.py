
filename = "A-large.in"
#filename = "A-small-attempt0.in"
#filename = "A-test.in"

lines = ()
with open(filename) as file:
	lines = file.read().splitlines()

number_of_sets = int(lines[0])

with open(filename+".solved","w") as outputfile:
	for i in range(0,number_of_sets):


		
		current = lines[i+1]
		(R,C,W) = current.split(" ")
		print str(R)+" "+str(C)+" "+str(W)

		R = int(R)
		W = int(W)
		C = int(C)


		if (W == 1):
			number = R*C
		else:
			number = (C/W) * R + (W-1)
			if ((C%W) > 0):
				number += 1

		line = "Case #"+str(i+1)+": "+str(number)
		print line
		outputfile.write(line+"\n")				
					