def standingovation(audience):
	people = 0
	answer = 0
	for (idx,x) in enumerate(audience):
		if int(x) > 0 and idx - people > 0:
			answer += idx - people 
			people += idx - people 
		people += int(x)
	return str(answer)

standingovation("09")


g = open("A-small-out.txt","w")


f = open("A-small.in","r")
d = f.read().split("\n")
n = int(d[0])

j = 1
for i in range(1,n+1):
	instance = d[i].split(" ")[1]
	g.write ("Case #" + str(i) + ": " + standingovation(instance) + "\n")