import sys

f = open(sys.argv[1],"r")
lines = f.read().split("\n")
lines = lines[1:]

count = 1
for l in lines:
	
	if int(l) == 0:
		print("Case #" + str(count) + ": INSOMNIA")
	
	else:
		
		seenDigits = set()
		current = 0

		while len(seenDigits)<10 :
			current = current + int(l)
			newdigits = [int(i) for i in str(current)]
			seenDigits.update(newdigits)
		
		print("Case #" + str(count) + ": " + str(current))

	count=count+1