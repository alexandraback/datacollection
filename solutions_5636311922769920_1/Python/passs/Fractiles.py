def make_number(K, C, chiffres):
	res = 0
	m = len(chiffres)
	for i in range(m):
		res += chiffres[i]*(K**i)
	return res


def check_positions(K, C, S):
	pos = []
	#if K == S:
	#	return range(1,K+1)
	if S*C < K:
		return "IMPOSSIBLE"
	else:
		n = K//C
		r = K - n*C
		for j in range(n):
			chif = range(j*C, j*C + C)
			pos.append(make_number(K, C, chif))
		if r > 0:
			chif = range(n*C, K)
			pos.append(make_number(K, C, chif))
	return pos



f = open("C://Users//Pavlo//Downloads//fractiles_large.in")
f_out = open("C://Users//Pavlo//Downloads//fractiles_out_large.txt", "a")
T = int(f.readline())
for i in range(T):
    temp = f.readline().split()
    [K, C, S] = [int(x) for x in temp]
    res = "Case #" + str(i+1) + ":"
    pos = check_positions(K, C, S)
    if pos == "IMPOSSIBLE":
    	res += " " + pos
    else:
    	for x in pos:
    		res += " " + str(x+1) 
    f_out.write(res + "\n")
    print(res)