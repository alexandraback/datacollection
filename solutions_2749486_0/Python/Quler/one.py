#Python

def process():
	return

if __name__=="__main__":
	N = int(raw_input())
	for i in range(N):
		vals = raw_input().split(' ')
		x = int(vals[0])
		y = int(vals[1])
		h = 0
		if abs(y) > abs(x):
			h = 1
		result = ""
		if h == 0:
			#x large
			r = 0
			if y != 0:
				if abs(y) == 1:
					if y == 1:
						result += "N"
					else:
						result += "S"
				else:
					if y > 0:
						result += "S"
					else:
						result += "N"
					r = abs(y) + 1
			tmp = 0
			index = 2
			while True:
				if index == r:
					if y > 0:
						result += "N"
					else:
						result += "S"
					if index % 2 != 0:
						tmp += 1
				else:
					if tmp < abs(x):
						if x > 0:
							if r == 0 or index < r:
								if index % 2 == 0:
									result += "W"
								else:
									result += "E"
									tmp += 1
							else:
								if index % 2 == 0:
									result += "E"
									tmp += 1
								else:
									result += "W"
						else:
							if r == 0 or index < r:
								if index % 2 == 0:
									result += "E"
								else:
									result += "W"
									tmp += 1
							else:
								if index % 2 == 0:
									result += "W"
									tmp += 1
								else:
									result += "E"
					else:
						if tmp == abs(x):
							break
						if x > 0:
							result += "EW"
						else:
							result += "WE"
				index += 1
		else:
			#y large
			r = 0
			if x != 0:
				if abs(x) == 1:
					if x == 1:
						result += "E"
					else:
						result += "W"
				else:
					if x > 0:
						result += "W"
					else:
						result += "E"
					r = abs(x) + 1
			tmp = 0
			index = 2
			while True:
				if index == r:
					if x > 0:
						result += "E"
					else:
						result += "W"
					if index % 2 != 0:
						tmp += 1
				else:
					if tmp < abs(y):
						if y > 0:
							if r == 0 or index < r:
								if index % 2 == 0:
									result += "S"
								else:
									result += "N"
									tmp += 1
							else:
								if index % 2 == 0:
									result += "N"
									tmp += 1
								else:
									result += "S"
						else:
							if r == 0 or index < r:
								if index % 2 == 0:
									result += "N"
								else:
									result += "S"
									tmp += 1
							else:
								if index % 2 == 0:
									result += "S"
									tmp += 1
								else:
									result += "N"
					else:
						if tmp == abs(y):
							break
						if y > 0:
							result += "NS"
						else:
							result += "SN"
				index += 1
		
		#print vals
		#print result
		print "Case #" + str(i+1) + ": " + result
