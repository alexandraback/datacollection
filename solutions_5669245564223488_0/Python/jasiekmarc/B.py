
import re

def locked(c, car):
	rex = '^[a-z]*'+'[^'+c+']'+c+'+[^'+c+']'+'[a-z]*$'
	if re.match(rex, car):
		return True
	else:
		return False

def wron(c, car):
	rex = '^[a-z]*'+c+'[^'+c+']+'+c+'[a-z]*$'
	if re.match(rex, car):
		return True
	else:
		return False

def whole(c, car):
	rex = '^'+c+'+$'
	if re.match(rex, car):
		return True
	else:
		return False

duzo = 1000000007

def fact(x):
	ret = 1
	for n in range(1, x + 1):
		ret = (ret * n) % duzo
	return ret

def solve():
	n = int(input())
	cars = input().split()
	mult = 1
	for c in range(ord('a'), ord('z')+1):
		c = chr(c)
		carst = cars
		wronc = list(filter(lambda x: wron(c, x), carst))
		carst = [car for car in carst if car not in wronc]
		lockedc = list(filter(lambda x: locked(c, x), carst))
		carst = [car for car in carst if car not in lockedc]
		wholec = list(filter(lambda x: whole(c, x), carst))
		carst = [car for car in carst if car not in wholec]
		begsc = list(filter(lambda x: x.startswith(c), carst))
		endsc = list(filter(lambda x: x.endswith(c), carst))
		carst = [car for car in carst if car not in begsc and car not in endsc]
		# print('\t======= ', c, ' ===========')
		# print('\t\tcars:', cars)
		# print('\t\twronc:', list(wronc))
		# print('\t\tlockedc:', list(lockedc))
		# print('\t\twholec:', list(wholec))
		# print('\t\tbegsc:', list(begsc))
		# print('\t\tendsc:', list(endsc))
		if wronc:
			return 0
		if len(lockedc) > 1:
			return 0
		if lockedc and len(wholec) + len(begsc) + len(endsc) > 0:
			return 0
		if len(begsc) > 1:
			return 0
		if len(endsc) > 1:
			return 0
		if lockedc:
			cars = carst + lockedc
			continue
		newstring = ''.join(wholec)
		if begsc:
			newstring = newstring + begsc[0]
		if endsc:
			newstring = endsc[0] + newstring
		cars = carst
		if newstring is not '':
			carst.append(newstring)
		mult = (mult * fact(len(wholec))) % duzo
		# print('\t\tmult =', mult)
	ret = (mult * fact(len(cars))) % duzo
	return ret

def main():
	t = int(input())
	for i in range(1, t+1):
		print('Case #{}: {}'.format(i, solve()))

if __name__ == '__main__':
	main()