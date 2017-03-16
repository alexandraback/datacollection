
filename = "A-large.in"
filename = "A-small-attempt2.in"
#filename = "A-test.in"

lines = ()
with open(filename) as file:
	lines = file.read().splitlines()

number_of_sets = int(lines[0])

def reverse(myi):
	rev = int(str(myi)[::-1])
	rev2 = int(str(rev)[::-1])
	if rev2 == myi:
		return rev
	else:
		print "inv " + str(myi)
		return myi


with open(filename+".solved","w") as outputfile:
	for i in range(0,number_of_sets):


		
		final = int(lines[i+1])
		counter = 0
		print "check: " + str(final)
		while final >= 1:
			if str(final)[-1:] == "1":
				rev = reverse(final)
				if rev < final:
					#print "SWITCH rev: "+str(rev)+" fin: "+str(final)
					final = rev
				else:
					#print "NOSWITCH rev: "+str(rev)+" fin: "+str(final)					
					final -= 1
			else:
					#print "NOSWITCH rev: "+str(rev)+" fin: "+str(final)					
					final -= 1
			counter += 1

		
		line = "Case #"+str(i+1)+": "+str(counter)
		print line
		outputfile.write(line+"\n")				
					