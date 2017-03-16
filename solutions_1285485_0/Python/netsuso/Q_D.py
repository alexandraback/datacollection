#!/usr/bin/python3

import sys
import math


class Hall:
	def __init__(self):
		self.hallmap = []
		self.myposition = ()
		self.sqsize = 500

	def addrow(self, txtrow):
		row = []
		nrow = len(self.hallmap)
		ncol = 0
		for square in txtrow:
			row.append(square)
			if square == "X":
				self.myposition = (ncol, nrow)
			ncol += 1
		self.hallmap.append(row)

	def getexitpoint(self, x, y, angle):
		if angle==0 or angle==360: return (self.sqsize, y, self.sqsize-x)
		if angle==90: return (x, -self.sqsize, self.sqsize+y)
		if angle==180: return (-self.sqsize, y, self.sqsize+x)
		if angle==270: return (x, self.sqsize, self.sqsize-y)

		sinus = abs(math.sin(math.radians(angle)))
		cosinus = abs(math.cos(math.radians(angle)))
		xright = self.sqsize-x
		xleft = self.sqsize+x
		ybottom = self.sqsize-y
		ytop = self.sqsize+y
		if angle>0 and angle<90:
			distanceforescapingright = xright / cosinus
			yforescapingright = distanceforescapingright * sinus
			if yforescapingright<=ytop:
				return (self.sqsize, y - yforescapingright, distanceforescapingright)
			else:
				distanceforescapingtop = ytop / sinus
				xforescapingtop = distanceforescapingtop * cosinus
				return (x + xforescapingtop, -self.sqsize, distanceforescapingtop)
		if angle>90 and angle<180:
			distanceforescapingleft = xleft / cosinus
			yforescapingleft = distanceforescapingleft * sinus
			if yforescapingleft<=ytop:
				return (-self.sqsize, y - yforescapingleft, distanceforescapingleft)
			else:
				distanceforescapingtop = ytop / sinus
				xforescapingtop = distanceforescapingtop * cosinus
				return (x - xforescapingtop, -self.sqsize, distanceforescapingtop)
		if angle>180 and angle<270:
			distanceforescapingleft = xleft / cosinus
			yforescapingleft = distanceforescapingleft * sinus
			if yforescapingleft<=ybottom:
				return (-self.sqsize, y + yforescapingleft, distanceforescapingleft)
			else:
				distanceforescapingbottom = ybottom / sinus
				xforescapingbottom = distanceforescapingbottom * cosinus
				return (x - xforescapingbottom, self.sqsize, distanceforescapingbottom)
		if angle>270 and angle<360:
			distanceforescapingright = xright / cosinus
			yforescapingright = distanceforescapingright * sinus
			if yforescapingright<=ybottom:
				return (self.sqsize, y + yforescapingright, distanceforescapingright)
			else:
				distanceforescapingbottom = ybottom / sinus
				xforescapingbottom = distanceforescapingbottom * cosinus
				return (x + xforescapingbottom, self.sqsize, distanceforescapingbottom)


	def processnormal(self, bigx, bigy, smallx, smally, angle):
		(exitx, exity, distance) = self.getexitpoint(smallx, smally, angle)
		smallx = exitx
		smally = exity
		if exitx == self.sqsize:
			bigx += 1
			smallx = -self.sqsize
		if exitx == -self.sqsize:
			bigx -= 1
			smallx = self.sqsize
		if exity == -self.sqsize:
			bigy -= 1
			smally = self.sqsize
		if exity == self.sqsize:
			bigy += 1
			smally = -self.sqsize
		return (bigx, bigy, smallx, smally, distance)


	def processmirror(self, bigx, bigy, smallx, smally, angle):
		if smallx == -self.sqsize:
			if smally == -self.sqsize:
				# Top-left corner (angles 270-360)
				if self.hallmap[bigy-1][bigx] == "#":
					if self.hallmap[bigy][bigx-1] == "#":
						# Pure reflection
						angle = angle - 180
						if angle < 0: angle += 1
						return (bigx-1, bigy-1, self.sqsize, self.sqsize, angle, True)
					else:
						# Normal vertical reflection
						angle = 270 - (angle - 270)
						return (bigx-1, bigy, self.sqsize, -self.sqsize, angle, True)
				elif self.hallmap[bigy][bigx-1] == "#":
					# Normal horizontal reflection
					angle = 360 - angle
					return (bigx, bigy-1, -self.sqsize, self.sqsize, angle, True)
				else:
					# Destroyed ray
					return (0, 0, 0, 0, 0, False)
			elif smally == self.sqsize:
				# Bottom-left corner (angles 0-90)
				if self.hallmap[bigy+1][bigx] == "#":
					if self.hallmap[bigy][bigx-1] == "#":
						# Pure reflection
						angle = angle + 180
						return (bigx-1, bigy+1, self.sqsize, -self.sqsize, angle, True)
					else:
						# Normal vertical reflection
						angle = 90 + (90 - angle)
						return (bigx-1, bigy, self.sqsize, self.sqsize, angle, True)
				elif self.hallmap[bigy][bigx-1] == "#":
					# Normal horizontal reflection
					angle = 360 - angle
					return (bigx, bigy+1, -self.sqsize, -self.sqsize, angle, True)
				else:
					# Destroyed ray
					return (0, 0, 0, 0, 0, False)
			else:
				# Left side (not a corner) - Normal vertical reflection
				angle = 90 + (90 - angle)
				if angle<0: angle += 360
				return (bigx-1, bigy, self.sqsize, smally, angle, True)

		elif smallx == self.sqsize:
			if smally == -self.sqsize:
				# Top-right corner (angles 180-270)
				if self.hallmap[bigy-1][bigx] == "#":
					if self.hallmap[bigy][bigx+1] == "#":
						# Pure reflection
						angle = angle - 180
						return (bigx+1, bigy-1, -self.sqsize, self.sqsize, angle, True)
					else:
						# Normal vertical reflection
						angle = 270 - (angle - 270)
						return (bigx+1, bigy, -self.sqsize, -self.sqsize, angle, True)
				elif self.hallmap[bigy][bigx+1] == "#":
					# Normal horizontal reflection
					angle = 360 - angle
					return (bigx, bigy-1, self.sqsize, self.sqsize, angle, True)
				else:
					# Destroyed ray
					return (0, 0, 0, 0, 0, False)
			elif smally == self.sqsize:
				# Bottom-right corner (angles 90-180)
				if self.hallmap[bigy+1][bigx] == "#":
					if self.hallmap[bigy][bigx+1] == "#":
						# Pure reflection
						angle = angle + 180
						return (bigx+1, bigy+1, -self.sqsize, -self.sqsize, angle, True)
					else:
						# Normal vertical reflection
						angle = 90 + (90 - angle)
						return (bigx+1, bigy, -self.sqsize, self.sqsize, angle, True)
				elif self.hallmap[bigy][bigx+1] == "#":
					# Normal horizontal reflection
					angle = 360 - angle
					return (bigx, bigy+1, self.sqsize, -self.sqsize, angle, True)
				else:
					# Destroyed ray
					return (0, 0, 0, 0, 0, False)
			else:
				# Right side (not a corner) - Normal vertical reflection
				angle = 90 + (90 - angle)
				if angle<0: angle += 360
				return (bigx+1, bigy, -self.sqsize, smally, angle, True)


		elif smally == -self.sqsize:
			# Top side (not a corner) - Normal horizontal reflection
			angle = 360 - angle
			return (bigx, bigy-1, smallx, self.sqsize, angle, True)
		elif smally == self.sqsize:
			# Bottom side (not a corner) - Normal horizontal reflection
			angle = 360 - angle
			return (bigx, bigy+1, smallx, -self.sqsize, angle, True)


	def processmyself(self, bigx, bigy, smallx, smally, angle, precision):
		if smallx == 0 and (angle == 90 or angle == 270):
			distancetozerox = self.sqsize
			yforzerox = 0
		else:
			distancetozerox = -smallx / math.cos(math.radians(angle))
			yforzerox = -smally + distancetozerox * math.sin(math.radians(angle))
		if abs(yforzerox)<precision:
			return (0, 0, 0, 0, distancetozerox, True)
		else:
			(bigx, bigy, smallx, smally, distance) = self.processnormal(bigx, bigy, smallx, smally, angle)
			return (bigx, bigy, smallx, smally, distance, False)

	def testray(self, angle, maxdistance, precision):
		maxdistance = maxdistance * self.sqsize * 2
		totaldistance = 0

		(bigx, bigy) = self.myposition
		(smallx, smally) = (0, 0)

		# Initial square (treat as normal instead of myself)
		(bigx, bigy, smallx, smally, sqdistance) = self.processnormal(bigx, bigy, smallx, smally, angle)
		totaldistance += sqdistance

		while True:
			sqtype = self.hallmap[bigy][bigx]
			if sqtype == ".":
				(bigx, bigy, smallx, smally, sqdistance) = self.processnormal(bigx, bigy, smallx, smally, angle)
				totaldistance += sqdistance
			elif sqtype == "#":
				sqdistance = 0
				(bigx, bigy, smallx, smally, newangle, validray) = self.processmirror(bigx, bigy, smallx, smally, angle)
				if not validray:
					return False
				angle = newangle
			elif sqtype == "X":
				(bigx, bigy, smallx, smally, sqdistance, finishedray) = self.processmyself(bigx, bigy, smallx, smally, angle, precision)
				totaldistance += sqdistance
				if finishedray and totaldistance <= maxdistance:
					return True


			if totaldistance > maxdistance:
				return False



numcase = 0
totalcases = int(sys.stdin.readline().strip())

while totalcases>0:
	line = sys.stdin.readline()
	if line == "": break

	numcase += 1
	totalcases -= 1

	data = line.strip().split(" ")
	height = int(data[0])
	width = int(data[1])
	maxdistance = int(data[2])
	hall = Hall()

	for i in range(0, height):
		hall.addrow(sys.stdin.readline().strip())

	count = 0
	degrees = 0
	last = -999
	first = 999
	while degrees<360:
		angle1 = degrees
		okfordegree = False
		# First, just return all those rays who pass over the myself square
		# (this is just to easily eliminate all cases when max distance doesn't
		# allow to reach any mirror)
		if hall.testray(angle1, maxdistance, 500) or hall.testray(angle1 + 0.5, maxdistance, 500):
			# Find whether the angle is valid by progresively increasing precision
			for i in range(0, 10):
				angle2 = angle1 + i * 0.1
				if hall.testray(angle2, maxdistance, 150):
					for j in range(0, 10):
						angle3 = angle2 + j * 0.01
						if hall.testray(angle3, maxdistance, 15):
							for k in range(0, 10):
								angle4 = angle3 + k * 0.001
								if hall.testray(angle4, maxdistance, 0.5) and angle4 > (last+0.3) and angle4 < (first + 360 - 0.3):
									count += 1
									if last == -999:
										first = angle4
									last = angle4
									okfordegree = True
									break
							if okfordegree: break
					if okfordegree: break
		degrees += 1
									
	print("Case #%d: %d" % (numcase, count))
