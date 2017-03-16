from collections import defaultdict

with open("t2.in") as f:
	content = f.readlines()

T = int(content[0])

case = 0
i = 1
while True:
    case += 1

    # Number of lines
    N = int(content[i])
    i += 1

    # Dict of numbers
    dct = defaultdict(int)

    for j in range(2*N-1):
    	# Go over a line and increase number of appearence
    	line = content[i].split()
    	i += 1
    	for n in line:
    		dct[n] += 1

    # Find odd numbers in dct
    lst = sorted([int(c) for c, n in dct.items() if n%2 == 1])
    lst = [str(n) for n in lst]
    string = " ".join(lst)
    print("Case #"+str(case)+": " + string)

    if case == T:
    	break

