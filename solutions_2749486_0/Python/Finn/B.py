f = open("B-small-attempt2.in")
fo = open("output.txt",'w')

def strategy(x, y):
	ans = ""
	if x > 0:
		ans += "WE" * x
	else:
		ans += "EW" * (-x)
	if y > 0:
		ans += "SN" * y
	else:
		ans += "NS" * (-y)
	return ans
case_num = int(f.readline().strip())
for i in range(0,case_num):
	X, Y = map(int, f.readline().strip().split())
	ans = strategy(X, Y)

	fo.write("Case #" + str(i+1) + ": " + ans + "\n")


f.close()
fo.close()