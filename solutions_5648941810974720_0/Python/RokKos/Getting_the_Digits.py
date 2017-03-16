dig = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
for test in range(int(raw_input())):
	bes = raw_input()

	rez = ""
	morabit = {dig[0] : bes.count("Z"), dig[2] : bes.count("W"), dig[4] : bes.count("U"), dig[6] : bes.count("X"), dig[8] : bes.count("G")}
	mora = "ZWXGU"
	for k in morabit.keys():
		for i in range(morabit[k]):
			for j in k:
				bes = bes.replace(j,"",1)
			rez += str(dig.index(k))

	#print rez
	if(len(bes) > 0):

		i = 0
		
		while i < len(dig):
			fl = True
			temp = ""
			for j in dig[i]:
				if(j not in bes):
					fl = False
					bes += temp
					break
				else:
					temp += j
					bes = bes.replace(j,"",1)
			if(fl):
				rez += str(i)
				#rint bes
			else:
				i+=1

	print "Case #{0}: {1}".format(test + 1, "".join(sorted(rez)))
