import math

def func(C,F,X):
	rate = 2
	time = 0
	while True:
		if (C/rate+X/(rate+F)) >= X/rate:
			return time+X/rate
		time+=C/rate
		rate+=F

input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")

T = int(input_file.readline().strip())
for i in range(T):
	para = [float(i) for i in input_file.readline().strip().split(" ")]
	output_file.write("Case #{}: {}\n".format(i+1, func(*para)))
