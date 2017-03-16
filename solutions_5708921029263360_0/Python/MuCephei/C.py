class Outfit():

	def __init__(self,jacket,pants,shirt,k):
		self.Jacket = jacket
		self.Pants = pants
		self.Shirt = shirt
		self.K = k
		if (self.Jacket == 0):
			self.missing = 0
		elif (self.Pants == 0):
			self.missing = 1
		elif (self.Shirt == 0):
			self.missing = 2

	def WornYesterday(self,jacket,pants,shirt):
		return (Jacket == jacket and Pants == pants and Shirt == shirt)

	def __eq__(self,other):
		if self.Jacket != 0 and other.Jacket != 0 and self.Jacket != other.Jacket:
			return False
		elif self.Pants != 0 and other.Pants != 0 and self.Pants != other.Pants:
			return False
		elif self.Shirt != 0 and other.Shirt != 0 and self.Shirt != other.Shirt:
			return False 
		return True

	def __add__(self,other):
		if self.Jacket == 0:
			jacket = other.Jacket
		else:
			jacket = self.Jacket

		if self.Pants == 0:
			pants = other.Pants
		else:
			pants = self.Pants

		if self.Shirt == 0:
			shirt = other.Shirt
		else:
			shirt = self.Shirt

		return (jacket,pants,shirt)

	def Combo(self,other):
		if (self.Jacket == other[0] and self.Pants == other[1]):
			return True

		if (self.Jacket == other[0] and self.Shirt == other[2]):
			return True

		if (self.Shirt == other[2] and self.Pants == other[1]):
			return True
		return False


def toString(data):
	result = ""
	for x in data:
		result = result + " " + str(x)
	return result

def C():
	rawinput = raw_input().split()

	jackets = int(rawinput[0])
	pants = int(rawinput[1])
	shirts = int(rawinput[2])
	maximum = int(rawinput[3])

	combinations = []

	for jacket in range(1,jackets+1):
		for pant in range(1,pants+1):
			combinations.append(Outfit(jacket,pant,0,maximum))
		for shirt in range(1,shirts+1):
			combinations.append(Outfit(jacket,0,shirt,maximum))

	for pant in range(1,pants+1):
		for shirt in range(1,shirts+1):
			combinations.append(Outfit(0,pant,shirt,maximum))

	days = 0
	outFits = ""

	SoYesterday = (-1,-1,-1)

	while(filter(lambda x: x.K != 0, combinations)):
		combinations = sorted(combinations, key=lambda x: x.Jacket)
		combinations = sorted(combinations, key=lambda x: x.Pants)
		combinations = sorted(combinations, key=lambda x: x.Shirt)
		combinations = sorted(combinations, key=lambda x: x.K)
		combinations.reverse()
		first = combinations[0]
		missing = first.missing
		complimentary = filter(lambda y: (y.missing != missing and y == first and y + first != SoYesterday),combinations)
		if (complimentary):
			SoYesterday = complimentary[0] + first
			toDecrement = []
			for combo in filter(lambda z: (z.Combo(SoYesterday)), combinations):
				if (combo.K == 0):
					completed = False
					break
				else:
					toDecrement.append(combo)
					completed = True
			if completed:
				for combo in toDecrement:
					combo.K -= 1
				outFits += toString(SoYesterday) + "\n"

				days += 1
			else:
				del (combinations[0])
		else:
			del (combinations[0])

	return (days,outFits)


times = input()

for x in range(times):
	result = C()
	print ("Case #" + str(x+1) + ": " + str(result[0]))
	print(result[1][:-1])