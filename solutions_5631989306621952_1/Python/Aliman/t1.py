with open("t1.in") as f:
	content = f.readlines()

case = 0
for word in content[1:]:
	case += 1
	result = word[0]
	for c in word[1:-1]:
		if c >= result[0]:
			result = c+result
		else:
			result += c
	print("Case #"+str(case)+": " + result)