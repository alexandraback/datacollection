
def powerOf(n,p):
	r = 0
	while n % p == 0:
		r += 1
		n //= p
	
	return r
	
def test(n, targets, values):
	if len(targets) == 0:
		return values
	if n == 0:
		return None
		
	for v in [2,3,4,6,8]:
		if any(t % v == 0 for t in targets):
			new_targets = []
			for t in targets:
				if t % v == 0:
					if t > v:
						new_targets.append(t//v)
				else:
					new_targets.append(t)
			result = test(n-1, new_targets, values + [v])
			if result:
				return result
				
	return None
		
def unique(s):
    seen = set()
    seen_add = seen.add
    return [ x for x in s if x not in seen and not seen_add(x)]

def case():
	r, n, m, k = map(int, input().split())
	
	answers = []
	
	
	for i in range(r):
		products = list(map(int, input().split()))
		
		#print(products)
		
		numberOf7s = max(powerOf(p,7) for p in products)
		numberOf5s = max(powerOf(p,5) for p in products)
		numberOfJust3s = max(0, max(powerOf(p,3)-powerOf(p,2) for p in products))
		numberOf6s = max(powerOf(p,3) for p in products) - numberOfJust3s
		numberOfJust2s = [powerOf(p,2)-powerOf(p,3) for p in products if powerOf(p,2)-powerOf(p,3) > 0]
		numberOfJust2s.sort()
		numberOfJust2s = unique(numberOfJust2s)
		ma = 0
		if len(numberOfJust2s) > 0:
			ma = max(numberOfJust2s)
	
		for i in range(k):
			while products[i] % 5 == 0:
				products[i] //= 5
			while products[i] % 7 == 0:
				products[i] //= 7
			
		result = "7" * numberOf7s + "5" * numberOf5s + "3" * numberOfJust3s + "6" * numberOf6s
		
		remaining = 12 - numberOf7s - numberOf5s - numberOfJust3s - numberOf6s
		
		if len(numberOfJust2s) > 0:
			if remaining == 1:
				if ma == 1:
					result += "2"
				elif ma == 2:
					result += "4"
				elif ma == 3:
					result += "8"
			elif remaining == 2:
				if numberOfJust2s[0] == 1:
					result += "2"
				elif numberOfJust2s[0] == 2:
					result += "4"
				elif numberOfJust2s[0] == 3:
					result += "8"
				if len(numberOfJust2s) > 1 and numberOfJust2s[1] == 2:
					result += "4"
				if len(numberOfJust2s) > 1 and numberOfJust2s[1] == 3:
					result += "8"
			else:
				if ma == 3*remaining:
					result = result.ljust(12,"8")
				elif ma == 3*remaining-1:
					result += "4"
					result = result.ljust(12,"8")
				else:
					result += "24"
					result = result.ljust(12,"8")
		
		if len(result) < 12:
			result = result.ljust(12,"2")
		if len(result) > 12:
			result = result[:12]
				
		answers.append(result)
		
	return "\n".join(answers)
	
	
for t in range(1,int(input())+1):
	print ("Case #%d:\n%s" % (t, case()))