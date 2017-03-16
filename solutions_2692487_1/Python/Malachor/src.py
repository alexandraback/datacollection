file = open("input.txt", "r")
file1 = open("output.txt", "w")

pi = 3.14



def main():
	t = 0
	a = 0
	n = 0
	temp = file.readline()
	temp = temp.split()
	t = int(temp[0])
	#print t
	for j in range(t):
		temp = file.readline()
		temp = temp.split()
		a, n = int(temp[0]), int(temp[1])
		temp = file.readline()
		temp = temp.split()
		m = [int(x) for x in temp]
		#print m
		m.sort()
		i = 0
		c = 0
		while i < n:
			#print c
			if c >= n:
				c = n
				break
			if a > m[i]:
				a += m[i]
				i += 1
				continue
			if i == len(m) - 1:
				c += 1
				if c >= n:
					c = n
				break
			if a == 1:
				i += 1
				c += 1
				continue
			c += 1
			a += a - 1
			#print "a=",a
			#print "c=",c

		print "Case #" + str(j+1) + ": " + str(c)
		file1.write("Case #" + str(j+1) + ": " + str(c) + "\n")

main()
