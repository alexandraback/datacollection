def getnext(coin):
	coin_str = ''.join(c for c in coin)
	coin2 = int(coin_str,2)
	coin2 += 2
	return list(str("{0:b}".format(coin2)))

def check(coin):
	coin_str = ''.join(c for c in coin)
	isjamcoin = True
	divlist = []
	for base in range(2,11):
		if isjamcoin==True:
			coin_base = int(coin_str,base)
			# print(str(base)+":"+str(coin_base))
			found_for_base = False
			for i in range(2,100):
				if coin_base%i==0:
					divlist.append(i)
					found_for_base = True
					break
			if found_for_base==False:
				isjamcoin = False

	return isjamcoin,divlist

t = int(input())

for itr in range(0,t):
	line = (input()).split()
	length = int(line[0])
	wanted = int(line[1])

	coin = []
	for i in range(0,length):
		if i==0 or i==length-1:
			coin.append('1')
		else:
			coin.append('0')

	print("Case #"+str(itr+1)+":")
	count = 0
	while count<wanted:
		isjamcoin,divlist = check(coin)
		if isjamcoin==True:
			count += 1
			print(''.join(c for c in coin),end=" ")
			for div in divlist:
				print(div,end=" ")
			print("")
		coin = getnext(coin)