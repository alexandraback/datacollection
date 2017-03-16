tc = int(raw_input())

s = []
smax = [];

for i in range(tc):
	temp = raw_input()
	temp = temp.split(' ')
	
	smax.append(int(temp[0]))
	t = []
	for j in temp[1]:
		t.append(int(j))
	s.append(t)

for i in range(tc):
	ans = 0
	for j in range(1, smax[i]+1):
		a = sum(s[i][:j])
		
		if (a + ans) < j:
			ans += (j - (a+ans))
		
	print "Case #"+str(i+1)+':', ans