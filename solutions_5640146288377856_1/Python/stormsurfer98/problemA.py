#Shrey Gupta
#Problem A

f1 = open('problemA.in', 'r')
f2 = open('problemA.out', 'w')

n = int(f1.readline().strip("\n"))

for x in range(n):
	data = f1.readline().strip("\n").split(" ")
	r = int(data[0]); c = int(data[1]); w = int(data[2])

	count = 0
	count += (r-1)*c
	if c%w == 0: count += c//w + w - 1
	else: count += c//w + w
	out = "Case #" + str(x+1) + ": " + str(count) + "\n"
	f2.write(out)