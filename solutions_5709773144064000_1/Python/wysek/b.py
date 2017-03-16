def finish(time, speed, X):
	return time + (X / speed)

def solve():
	C, F, X = [float(x) for x in input().split()]
	speed = 2.0
	time = 0.0

	while True:
		ifNotBuy = finish(time, speed, X)
		ifBuy = finish(time+(C/speed), speed+F, X)
	#	print(ifNotBuy, ifBuy)
		if ifBuy < ifNotBuy:
			time += C/speed
			speed += F
		else:
			return finish(time, speed, X)

def main():
	T = int(input())
	for t in range(1, T+1):
		r = solve()
		print("Case #%d: %.7f" % (t, r))

if __name__ == '__main__':
	main()

