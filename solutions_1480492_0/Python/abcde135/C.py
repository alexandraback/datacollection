import copy

def write_case(n, s, f):
	f.write("Case #%i: %s\n" % (n, s))

class Car:
	def __init__(self, c, s, x):
		self.lane = c
		self.speed = s
		self.position = x

def update(cars):
	for i in range(len(cars)):
		cars[i].position += cars[i].speed

	for i in range(1, len(cars)):
		j = i-1
		while j >= 0 and cars[j].position > cars[j+1].position:
			c = cars[j]
			cars[j] = cars[j+1]
			cars[j+1] = c

	for i in range(len(cars)-2):
		if cars[i].position > cars[i+2].position-5:
			return False

	lane = 0
	for car in cars:
		car.lane = lane
		lane = 1 - lane

	return True

def check(cars):
	prevSpeed = 0
	for c in cars:
		if prevSpeed > c.speed:
			return False
		prevSpeed = c.speed
	return True

def solve(infilename, outfilename):
	f = open(infilename)
	g = open(outfilename, 'w')

	T = int(f.readline())
	for n in range(T):
		N = int(f.readline())
		cars = [None] * N
		maxspeed = 0
		for i in range(N):
			(y, s, x) = f.readline().split()
			s = float(s)
			x = float(x)
			if y == 'L':
				y = 0
			else:
				y = 1
			cars[i] = Car(y, s, x)

			if s > maxspeed:
				maxspeed = s

		cars.sort(key=lambda y:y.position)

		for car in cars:
			car.speed = 5 * car.speed / maxspeed

		lane = 0
		for car in cars:
			car.lane = lane
			lane = 1-lane

		result = "Possible"
		for i in range(1000000):
			if check(cars):
				result = "Possible"
				break
			b = update(cars)
			if not b:

				maxk = 0
				maxin = 0
				for k in range(len(cars)-2):
					d = cars[k].position + 5 - cars[k+2].position
					if d > maxin:
						maxin = d
						maxk = k

				speed_diff = (cars[maxk].speed - cars[maxk+2].speed) * maxspeed / 5
				if speed_diff == 0:
					time_diff = 0
				else:
					time_diff = maxin / speed_diff
				print maxk, maxin, speed_diff, time_diff
				result = "%.17f" % ( ( (i+1) * 5 / maxspeed) - time_diff)
				break

		write_case(n+1, result, g)
		
	f.close()
	g.close()






if __name__ == "__main__":
#	solve('C-sample.in', 'C-sample.out')
#	solve('C-sample-large.in', 'C-sample-large.out')
	solve('C-small-attempt0.in', 'C-small-attempt0.out')
#	solve('C-large.in', 'C-large.out')
