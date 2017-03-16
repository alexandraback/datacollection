def solve(energy, recovery, gains):
	minimum_values = [0]*len(gains)
	max_value = 0
	for n,val in enumerate(gains):
		aumen_sum = 0
		ncounter = n
		while aumen_sum < energy and ncounter < len(gains):
			if val < gains[ncounter]:
				minimum_values[n] = energy-aumen_sum
				break
			ncounter+=1
			aumen_sum+=recovery
	return solving(energy,recovery,gains,minimum_values)

def solving(energy,recovery,gains,minimum_values):
	i = 0
	resulting = 0
	current_energy = energy
	while i < len(gains):
		if current_energy > minimum_values[i]:
			resulting+=(current_energy - minimum_values[i])*gains[i]
			current_energy = minimum_values[i]
		i+=1
		current_energy+=recovery
	return resulting

#f = open("input.txt")
f = open("B-large.in")
t = int(f.readline())
i=1
while i<=t:
	(a,b,c) = f.readline().split(" ")
	values = [int(x) for x in f.readline().split(" ")]
	n = int(a)
	m = int(b)
	print "Case #"+str(i)+":",solve(n,m,values)
	i+=1