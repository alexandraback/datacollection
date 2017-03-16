import sys

fin = open(sys.argv[1], "r")
fout = open("C.out", "w")

T = int(fin.readline())
for m in xrange(T):
	L, X = map(long,fin.readline().split())
	a = fin.readline().split()[0]
	string = ''
	out = 'KUKU'
	if X < 12:
		for n in range(X):
			string = string + a

#	print string
		n = 0
		let = '1'
		sign = 1
		while (n < len(string)):
			newlet = string[n]
			if let == '1':
				let = newlet
			elif let == 'i' and newlet == 'j':
				let = 'k'
			elif let == 'j' and newlet == 'i':
				let = 'k'
				sign = -sign
			elif let == 'i' and newlet == 'k':
				let = 'j'
				sign = -sign
			elif let == 'k' and newlet == 'i':
				let = 'j'
			elif let == 'k' and newlet == 'j':
				let = 'i'
				sign = -sign
			elif let == 'j' and newlet == 'k':
				let = 'i'
			elif let == 'j' and newlet == 'j':
				sign = -sign
				let = '1'
			elif let == 'i' and newlet == 'i':
				sign = -sign
				let = '1'
			elif let == 'k' and newlet == 'k':
				sign = -sign
				let = '1'
			n += 1	
			#print let
			#print sign	
			if let == 'i' and sign == 1:
				break								
		nlow = n

		n = len(string)-1
		let = '1'
		sign = 1
		while (n >= 0):
			newlet = string[n]
			if let == '1':
				let = newlet
			elif let == 'i' and newlet == 'j':
				let = 'k'
				sign = -sign
			elif let == 'j' and newlet == 'i':
				let = 'k'
			elif let == 'i' and newlet == 'k':
				let = 'j'
			elif let == 'k' and newlet == 'i':
				let = 'j'
				sign = -sign
			elif let == 'k' and newlet == 'j':
				let = 'i'
			elif let == 'j' and newlet == 'k':
				let = 'i'
				sign = -sign
			elif let == 'j' and newlet == 'j':
				sign = -sign
				let = '1'
			elif let == 'i' and newlet == 'i':
				sign = -sign
				let = '1'
			elif let == 'k' and newlet == 'k':
				sign = -sign
				let = '1'
			n -= 1	
			#print let
			#print sign	
			if let == 'k' and sign == 1:
				break
		nhigh = n					
		if nhigh < nlow:
			out = 'NO'
		else:	
			newstring=string[nlow:nhigh+1]
			n = 0
			let = '1'
			sign = 1
			while (n < len(newstring)):
				newlet = newstring[n]
				if let == '1':
					let = newlet
				elif let == 'i' and newlet == 'j':
					let = 'k'
				elif let == 'j' and newlet == 'i':
					let = 'k'
					sign = -sign
				elif let == 'i' and newlet == 'k':
					let = 'j'
					sign = -sign
				elif let == 'k' and newlet == 'i':
					let = 'j'
				elif let == 'k' and newlet == 'j':
					let = 'i'
					sign = -sign
				elif let == 'j' and newlet == 'k':
					let = 'i'
				elif let == 'j' and newlet == 'j':
					sign = -sign
					let = '1'
				elif let == 'i' and newlet == 'i':
					sign = -sign
					let = '1'
				elif let == 'k' and newlet == 'k':
					sign = -sign
					let = '1'
				n += 1
			if let == 'j' and sign == 1:
				out = 'YES'
			else:
				out = 'NO'
	else:		
#		print 'here'		
		for n in range(4):
			string = string + a

#	print string
		n = 0
		let = '1'
		sign = 1
		while (n < len(string)):
			newlet = string[n]
			if let == '1':
				let = newlet
			elif let == 'i' and newlet == 'j':
				let = 'k'
			elif let == 'j' and newlet == 'i':
				let = 'k'
				sign = -sign
			elif let == 'i' and newlet == 'k':
				let = 'j'
				sign = -sign
			elif let == 'k' and newlet == 'i':
				let = 'j'
			elif let == 'k' and newlet == 'j':
				let = 'i'
				sign = -sign
			elif let == 'j' and newlet == 'k':
				let = 'i'
			elif let == 'j' and newlet == 'j':
				sign = -sign
				let = '1'
			elif let == 'i' and newlet == 'i':
				sign = -sign
				let = '1'
			elif let == 'k' and newlet == 'k':
				sign = -sign
				let = '1'
			n += 1	
			#print let
			#print sign	
			if let == 'i' and sign == 1:
				break								
		nlow = n
		if nlow == len(string):
			out = 'NO'
#		print nlow	

		n = len(string)-1
		let = '1'
		sign = 1
		while (n >= 0):
			newlet = string[n]
			if let == '1':
				let = newlet
			elif let == 'i' and newlet == 'j':
				let = 'k'
				sign = -sign
			elif let == 'j' and newlet == 'i':
				let = 'k'
			elif let == 'i' and newlet == 'k':
				let = 'j'
			elif let == 'k' and newlet == 'i':
				let = 'j'
				sign = -sign
			elif let == 'k' and newlet == 'j':
				let = 'i'
			elif let == 'j' and newlet == 'k':
				let = 'i'
				sign = -sign
			elif let == 'j' and newlet == 'j':
				sign = -sign
				let = '1'
			elif let == 'i' and newlet == 'i':
				sign = -sign
				let = '1'
			elif let == 'k' and newlet == 'k':
				sign = -sign
				let = '1'
			n -= 1	
			#print let
			#print sign	
			if let == 'k' and sign == 1:
				break
		nhigh = n
		if nhigh == -1:
			out = 'NO'
#		print nhigh	

		nmid = (X-8) % 4
#		print L, nmid

		if out != 'NO':
			stringmid = ''

			for n in range(nmid):
				stringmid = stringmid + a
#			print string[nlow:4*L]
#			print string[0:nhigh+1]	
			newstring = string[nlow:4*L]+ stringmid + string[0:nhigh+1]
#			print newstring, len(newstring), nmid
			n = 0
			let = '1'
			sign = 1
			while (n < len(newstring)):
				newlet = newstring[n]
				if let == '1':
					let = newlet
				elif let == 'i' and newlet == 'j':
					let = 'k'
				elif let == 'j' and newlet == 'i':
					let = 'k'
					sign = -sign
				elif let == 'i' and newlet == 'k':
					let = 'j'
					sign = -sign
				elif let == 'k' and newlet == 'i':
					let = 'j'
				elif let == 'k' and newlet == 'j':
					let = 'i'
					sign = -sign
				elif let == 'j' and newlet == 'k':
					let = 'i'
				elif let == 'j' and newlet == 'j':
					sign = -sign
					let = '1'
				elif let == 'i' and newlet == 'i':
					sign = -sign
					let = '1'
				elif let == 'k' and newlet == 'k':
					sign = -sign
					let = '1'
				n += 1
#				print let, sign	
			if let == 'j' and sign == 1:
				out = 'YES'
			else:
				print 'here'
				out = 'NO'

#	print 'hello'		
#	sys.stdout.write("Case #" + str(m+1) + ": " + out + "\n")		
	fout.write("Case #" + str(m+1) + ": " + out + "\n")
#	fout.close()