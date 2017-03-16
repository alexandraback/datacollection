from string import ascii_lowercase as alphabet

T = int(input())
q = 0

pprint = print
def gprint (*args, **kwargs):
	global q
	pprint ("Case #{}:".format(q+1), *args, **kwargs)

print = gprint

def valid (car):
	was = {x:False for x in alphabet}

	for i, char in enumerate(car):
		if was[char] and car[i-1] != char: return False
		was[char] = True

	return True

class Struct:
	def __init__ (self):
		self.empty  = True
		self.before = None
		self.after  = None
		self.count  = 0


for q in range (T):
	N = int(input())
	data = input().strip().split()


	if not all ([valid(x) for x in data]):
		print ("0")
		continue

	chains = {x:Struct() for x in alphabet}
	
	count = 0

	for car in data:
		
		Break = False
		for char in car[1:-1]:
			if not chains[char].empty:
				Break = True
				break 
	

		if Break: break

		if chains[car[0]].after is not None: break
		
		chains[car[0]].empty = False
		if car[-1] == car[0]: chains[car[0]].count += 1
		else: 
			if not chains[car[-1]].before is None: break
			chains[car[0 ]].after  = car[-1]
			chains[car[-1]].before = car[0]

		for char in car[1:-1]:
			chains[char].empty  = False
			chains[char].before = char
			chains[char].after  = char

		count +=1


	if count != len(data):
		print (0)
		continue

	comp = 0
	for char in alphabet:
		if not chains[char].empty and chains[char].before is None: comp += 1

	res = comp

	for char in alphabet:
		if not chains[char].empty and chains[char].count >0:
			for x in  range(2, chains[char].count+1):
				res = (res * x) % 1000000007

	print (res)

