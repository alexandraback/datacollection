import itertools

filename = "B-large.in"
filename = "B-small-attempt0.in"
#filename = "B-test.in"

lines = ()
with open(filename) as file:
	lines = file.read().splitlines()

number_of_sets = int(lines[0])

with open(filename+".solved","w") as outputfile:
	for i in range(0,number_of_sets):


		number = 0
		first = lines[i*3 + 1].split(" ")
		KEYBOARD = lines[i*3 + 2]
		TARGET = lines[i*3 + 3]
		K = int(first[0])
		L = int(first[1])
		S = int(first[2])

		invalid = False
		for t in TARGET:
			if t not in KEYBOARD:
				number = 0.0
				invalid = True
				break

		if not invalid:
			overlap = 0
			if (TARGET.count(TARGET[0]) == L):
				print "all the same: " + TARGET
				overlap = L
			else:
				for ti in range(1,L):
					if (TARGET[:ti] == TARGET[-ti:]):
						overlap = ti
						print TARGET[:ti]+" "+TARGET[-ti:]
					
			if overlap == L:
				step = 1
			elif overlap > 0:
				step = L - (overlap)
			else:
				step = L

			#print "step: " + str(step)
			#print "overlap: " + str(overlap)

			counter = 0
			max_o = 0
			while((counter+L) <= S):
				max_o += 1
				counter += step
			print "max: " + str(max_o)
			
			# max_o is number of maximal bananas
			p = dict()
			for t in TARGET:
				p[t] = float(KEYBOARD.count(t))/len(KEYBOARD)
			print p

			prob = 1.0
			for T in TARGET:
				prob *= p[T]
			#prob = max_o * prob
			print "prob: "+str(prob)
			#print KEYBOARD
			#perms = [''.join(x) for x in itertools.combinations_with_replacement(KEYBOARD,S)]
			#print perms
			#o = 0
			#for p in perms:
			#	o += p.count(TARGET)
			#print (float(max(o,1))/len(perms))

			number = max_o - max_o*prob



		line = "Case #"+str(i+1)+": "+str(round(number,7))
		print line
		outputfile.write(line+"\n")				
					