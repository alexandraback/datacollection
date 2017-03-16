import math

def Factorial(n):
	ans = 1
	for i in xrange(1, n+1):
		ans = (ans*i) % 1000000007
	return ans

def ReduceCars(cars):
	sol = 0
	uni_car = {}
	empiezan = {}
	acaban = {}
	medios = {}
	new_cars = []
	count = 0
	for car in cars:
		new = ''
		previo = ''
		for c in car:
			if (c != previo):
				new += c
			previo = c
		first = new[0]
		last = new[-1]
		if (first in empiezan):
			empiezan[first].append(count)
		else:
			empiezan[first] = [count]
		if (last in acaban):
			acaban[last].append(count)
		else:
			acaban[last] = [count]
		if (len(new) == 1):
			if (new in uni_car):
				uni_car[new].append(count)
			else:
				uni_car[new] = [count] 
		else:
			if (new[0] == new[-1]):
				sol = -1
		if (len(new) > 2):
			for i in xrange(1, len(new)-1):
				if (new[i] in medios):
					medios[new[i]].append(count)
				else:
					medios[new[i]] = [count]
		new_cars.append(new)
		count += 1
	cars = new_cars[:]
#	print cars

	for m in medios.keys():
		if (m in empiezan) or (m in acaban):
			sol = -1
#			print 'medios ' + m
			break

	for letter, lista in empiezan.iteritems():
		num_acaban = 0
		if (letter in acaban):
			num_acaban = len(acaban[letter])
		if (abs(num_acaban - len(lista)) > 1):
			sol = -1
#			print 'empiezan ' + letter
			break

	for letter, lista in acaban.iteritems():
		num_empiezan = 0
		if (letter in empiezan):
			num_empiezan = len(empiezan[letter])
		if (abs(num_empiezan - len(lista)) > 1):
			sol = -1
#			print 'acaban ' + letter
			break

	if (sol == -1):
		return sol

	sol = 1
	borrar = []
	for letter, lista in uni_car.iteritems():
		sol = (sol*Factorial(len(lista))) % 1000000007
		borrar.extend(lista[1:])

	if (len(borrar) > 0):
		borrar.sort(reverse=True)
		for b in borrar:
			cars.pop(b)
#	print cars

	# Hasta aqui ya hemos quitado los coches con una letra y hemos dejado uno testimonial

	# Vamos a comprobar que lo que queda tiene soluciona (no hay dos coches con mas de una letra que acaben o empiecen por la misma).
	empiezan = {}
	acaban = {}
	uni = {}
	count = 0
	error = 0
	for c in cars:
		if (len(c) > 1):
			first = c[0]
			last = c[-1]
			if (first == last):
				error = -1
			if (first in empiezan):
				empiezan[first].append(count)
			else:
				empiezan[first] = [count]
			if (last in acaban):
				acaban[last].append(count)
			else:
				acaban[last] = [count]
		else:
			if (c in uni):
				print 'MAAAAAL'
			else:
				uni[c] = [count]
		count += 1

	new_cars = []
	for letter, lista in empiezan.iteritems():
		if (len(lista) > 1):
			error = -1
	for letter, lista in acaban.iteritems():
		if (len(lista) > 1):
			error = -1
	if (error == -1):
		sol = -1
		return sol

	borrar = []
	for letter, lista in uni.iteritems():
		if (letter in empiezan) or (letter in acaban):
			borrar.extend(lista)
	if (len(borrar) > 0):
		borrar.sort(reverse=True)
		for b in borrar:
			cars.pop(b)
#	print cars

	# Sabemos que hay solucion, juntamos los maximos que podamos
	count = 1
	while (count > 0):
		count = 0
		new_cars = []
		usado = []
		for i in xrange(len(cars)):
			if (i not in usado):
				new = ''
				for j in xrange(len(cars)):
					if (j != i) and (j not in usado) and (i not in usado):
						if (cars[j][0] == cars[i][-1]):
							new = cars[i] + cars[j]
							usado.append(i)
							usado.append(j)
							count += 1
							break
						elif (cars[i][0] == cars[j][-1]):
							new = cars[j] + cars[i]
							usado.append(i)
							usado.append(j)
							count += 1
							break
				if (new != ''):
					new_cars.append(new)
				else:
					if (i not in usado):
						new_cars.append(cars[i])
		cars = new_cars[:]
#		print 'New cars ',

#	print cars
	empiezan = {}
	acaban = {}
	uni = {}
	count = 0
	error = 0
	for c in cars:
		if (len(c) > 1):
			first = c[0]
			last = c[-1]
			if (first == last):
				error = -1
			if (first in empiezan):
				empiezan[first].append(count)
			else:
				empiezan[first] = [count]
			if (last in acaban):
				acaban[last].append(count)
			else:
				acaban[last] = [count]
		else:
			if (c in uni):
				print 'MAAAAAL'
			else:
				uni[c] = [count]
		count += 1

	new_cars = []
	for letter, lista in empiezan.iteritems():
		if (len(lista) > 1):
			error = -1
	for letter, lista in acaban.iteritems():
		if (len(lista) > 1):
			error = -1
	if (error == -1):
		sol = -1
		return sol

	sol = (sol*Factorial(len(cars))) % 1000000007
	return sol

for case in xrange(input()):
	sol = 0
	N = int(input())
	cars = raw_input().split()

	temp = ReduceCars(cars)
	if (temp > 0):
		sol = temp

	print 'Case #%d: %s' % (case+1, sol)
