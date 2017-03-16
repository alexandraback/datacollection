#!/usr/bin/python
import sys

def main():

	f = open(sys.argv[1], 'r')
	for lineNum, line in enumerate(f):
		line = line.rstrip('\n')
		if lineNum == 0:
			continue

		(c, f, x) = (float(n) for n in line.split(' '))
		# print "C: {} F: {} X: {}".format(c, f, x)
		print "Case #{}: {}".format(lineNum, round(analyze(c, f, x),7))

def analyze(c, f, x):
	numCookies = 0
	ratePerSecond = 2
	timeElapsed = 0
	numFarmsBought = 0

	while numCookies < x:
		currentWinTime = (x-numCookies)/ratePerSecond
		timeToNextFarm = (c-numCookies)/ratePerSecond
		winningTimeWithExtraFarm = (x - (numCookies - c))/(ratePerSecond + f)
		# print "Elapsed: {}, Winning Time: {}, Cookies: {}, Farms: {}, Next Farm: {}, Rate: {}".format(timeElapsed, currentWinTime, numCookies, numFarmsBought, timeToNextFarm, ratePerSecond)
		if currentWinTime <= timeToNextFarm or winningTimeWithExtraFarm > currentWinTime:
			timeElapsed += currentWinTime
			numCookies += currentWinTime * ratePerSecond
			# print "Done!"
			return timeElapsed


		# can afford farm
		if numCookies >= c:
			# print "Win Time with Extra Farm: {}, Cookies if Bought: {}, New Rate: {}".format(winningTimeWithExtraFarm, (numCookies - c), (ratePerSecond + f))
			if winningTimeWithExtraFarm <= currentWinTime:
				# buy farm
				numCookies -= c
				ratePerSecond += f
				numFarmsBought += 1
				timeToNextFarm = (c-numCookies)/ratePerSecond
				# print "Time to next farm if bought: {}".format(timeToNextFarm)
				timeElapsed += min(timeToNextFarm, winningTimeWithExtraFarm)
				numCookies += timeToNextFarm * ratePerSecond
				continue

		timeElapsed += min(timeToNextFarm, winningTimeWithExtraFarm)
		numCookies += min(timeToNextFarm, winningTimeWithExtraFarm) * ratePerSecond
		# if numFarmsBought > 1:
		# 	break

	# print "Cookies: {}, Farms: {}, Time: {}".format(numCookies, numFarmsBought, timeElapsed)


if __name__ == "__main__":
	main()