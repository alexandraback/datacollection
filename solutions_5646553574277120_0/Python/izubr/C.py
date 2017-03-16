import itertools

def removing(coins, L, resheto, added, maximum):
	for subset in itertools.combinations(coins,L):
		summ = sum(subset) + added
		if maximum >= summ:
		#print summ
			if summ in resheto:
				resheto.remove(summ)
	return resheto

def to_add(coins):
	coins.sort()
	print coins
	if coins[0] != 1:
		return 1
	for i in range(1, len(coins)):
		if coins[i] - coins [i-1] > 1:
			return coins[i-1]+1
	return coins[len(coins) - 1] + 1

def function():
	c,d,v  = raw_input("").split(" ")
	c,d,v = int(c), int(d), int(v)
	coins = raw_input("").split(" ")
	coins = [int(coin) for coin in coins]
	resheto = set(range(1, v + 1))
	#print resheto
	for L in range(len(coins) + 1):
		resheto = removing(coins, L, resheto, 0, v)
	added_numbers = 0
	while resheto:
		#print resheto
		#print "@@"
		#print coins
		#print "!!"
		added_numbers += 1
		#adding = to_add(coins)
		adding = min(resheto)
		#print adding
		if adding in resheto:
			resheto.remove(adding)
		for L in range(len(coins) + 1):
			resheto = removing(coins, L, resheto, adding, v)
		coins.append(adding)
	#print coins
	return added_numbers

t = int(raw_input(""))
for i in range(1, t + 1):
	print "Case #%s: %s" % (i, function())
    