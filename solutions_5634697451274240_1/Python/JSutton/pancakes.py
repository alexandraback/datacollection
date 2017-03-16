infile = open("B-large.in","r")
outfile = open("B-large.out","w")

T = int(infile.readline())
print(T)

def solver(pancake_stack):
	flips = 0
	modulo = 0
	if pancake_stack[0] == "-":
		modulo = 1
	print("modulo: {0}".format(modulo))
	if len(pancake_stack) == 1:
		return modulo
	for pancake in range(len(pancake_stack)-1):
		if pancake_stack[pancake] != pancake_stack[pancake+1]:
			flips += 1
	if flips % 2 != modulo:
		return flips + 1
	return flips

for case in range(T):
    pancake_stack = infile.readline().strip()
    print(pancake_stack)
    solution = solver(pancake_stack)
    print(solution)
    outfile.write("Case #" + str(case+1) + ": " + str(solution) + "\n")

infile.close()
outfile.close()