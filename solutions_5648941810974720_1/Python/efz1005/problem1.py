numbers = [
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

T = input()

for qw in xrange(1, T + 1):
	print "Case #%d:" % qw,

	string = list(raw_input())
	#string_copy = string[:]

	#final = ""
	#times = [float("inf") for i in xrange(10)]

	final = []

	while len(string) > 0:
		if "Z" in string:
			final.append(0)
			for j in numbers[0]:
				string.remove(j)
		elif "X" in string:
			final.append(6)
			for j in numbers[6]:
				string.remove(j)
		elif "G" in string:
			final.append(8)
			for j in numbers[8]:
				string.remove(j)
		elif "W" in string:
			final.append(2)
			for j in numbers[2]:
				string.remove(j)
		elif "T" in string and "H" in string:#eight is out
			final.append(3)
			for j in numbers[3]:
				string.remove(j)
		elif "R" in string:#4
			final.append(4)
			for j in numbers[4]:
				string.remove(j)
		elif "F" in string:
			final.append(5)
			for j in numbers[5]:
				string.remove(j)
		elif "S" in string:
			final.append(7)
			for j in numbers[7]:
				string.remove(j)
		elif "O" in string:
			final.append(1)
			for j in numbers[1]:
				string.remove(j)
		elif "N" in string:
			final.append(9)
			for j in numbers[9]:
				string.remove(j)
	final.sort()

	print "".join([str(i) for i in final])