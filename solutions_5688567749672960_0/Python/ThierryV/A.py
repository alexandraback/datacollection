for tc in range(1, int(raw_input())+1):
	#print
	number = int(raw_input())

	counter = 0

	i = 1
	while (i <= number):



		counter +=1
		if i==number:
			y = counter
			break


		#print 'i, counter', i, counter
		iRev = str(i)[::-1]
		#print 'iRev, number', iRev, number
		
		if int(iRev) == int(number):
			y = counter
			break

		if int(iRev) < int(number):
			if int(iRev) > i+1:
				if int(iRev) > int(str(i+1)[::-1]):
					i = int(iRev)
				else:
					if int(str(i+1)[::-1]) <= number:
						i = i+1
					else:
						i = int(iRev)
			else:
				i=i+1
	
		else:
			i = i+1


	y = counter

	print "Case #{}: ".format(tc) + "{}".format(y)