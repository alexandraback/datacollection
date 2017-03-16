infile = open("A-large.in","r")
outfile = open("A-large.out","w")

T = int(infile.readline())
print(T)

def solver(N):
	if N == 0:
		return "INSOMNIA"
	else:
		digits = []
		temp = N
		count = 0
		while len(digits) < 10:
			tempstr = str(temp)
			for character in tempstr:
				if character not in digits:
					digits.append(character)
			temp += N
			count += 1
		return count * N

for case in range(T):
    N = int(infile.readline())
    print(N)
    solution = solver(N)
    print(solution)
    outfile.write("Case #" + str(case+1) + ": " + str(solution) + "\n")

infile.close()
outfile.close()