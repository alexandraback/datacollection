f = open("B-large.in.txt", "r")
f2 = open("B-large.out.txt", "w")
num_cases = int(f.readline().strip())

for i in range(num_cases):
	p = f.readline().strip().split(' ')
	C = float(p[0])
	F = float(p[1])
	X = float(p[2])
	prev_b_time = 0.0
	rate = 2
	time = prev_b_time + X/rate
	while True:
		b_time = C/rate
		rate += F
		prev_b_time += b_time
		tt_time = prev_b_time + X/rate
		if tt_time < time :
			time = tt_time
		else :
			break;
	f2.write("Case #" + str(i+1) + ": " + str(time) + "\n")
f.close()
f2.close()
