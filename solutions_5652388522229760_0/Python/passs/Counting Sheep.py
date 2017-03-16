def last_number(N):
	if N == 0:
		return "INSOMNIA"
	digits = {}
	N_current = N
	while(len(digits) < 10):
		N_str = str(N_current)
		for ch in N_str:
			digits[ch] = 1
		N_current += N
	return N_current - N



f = open("C://Users//Pavlo//Downloads//sheep.in")
f_out = open("C://Users//Pavlo//Downloads//sheep_out.txt", "a")
T = int(f.readline())
for i in range(T):
    N = int(f.readline())
    res = last_number(N)
    f_out.write("Case #" + str(i+1) + ": " + str(res) + "\n")
    print("Case #" + str(i+1) + ": " + str(res) + "\n")