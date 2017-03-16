def check_positions(K, C, S):
	if K == S:
		return range(1,K+1)
	else:
		return []




f = open("C://Users//Pavlo//Downloads//fractiles.in")
f_out = open("C://Users//Pavlo//Downloads//fractiles_out.txt", "a")
T = int(f.readline())
for i in range(T):
    temp = f.readline().split()
    [K, C, S] = [int(x) for x in temp]
    res = "Case #" + str(i+1) + ":"
    pos = check_positions(K, C, S)
    for x in pos:
    	res += " " + str(x) 
    f_out.write(res + "\n")
    print(res)