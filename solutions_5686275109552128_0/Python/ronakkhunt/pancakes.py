tc = int(raw_input())

pancakes = []
for i in range(tc):
	d = int(raw_input())
	temp = raw_input()
	temp = temp.split(' ')
	t = []
	for j in range(d):
		t.append(int(temp[j]))
	pancakes.append(t)


for i in range(tc):
	ans = max(pancakes[i])
	
	z = 2
	while z < ans:
		ans = min(ans, sum([(x - 1) // z for x in pancakes[i]]) + z)
		z += 1
	print "Case #"+str(i+1)+":",ans