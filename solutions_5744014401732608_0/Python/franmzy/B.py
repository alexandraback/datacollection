# -*- coding: utf-8 -*-
######################################################
##                                                  ##
##  Fran Muñoz                                      ##
##  email: fran.mzy@gmail.com                       ##
##  UVA user: franmzy                               ##
##  Linkedin: https://www.linkedin.com/in/franmzy   ##
##                                                  ##
######################################################

MAX_B = 55
barray = [0]


# for i in range(MAX_B):
# 	barray.append(sum(barray)+1)

# print (barray)


n_cases = int(input())

for i_case in range(n_cases):
	B, M = list(map(int, input().split()))
	print('Case #{0}:'.format(i_case+1), end=' ')

	if 2**(B-2) >= M:
		print("POSSIBLE")

		binM = bin(M)[2:]
		if M == 2**(B-2):
			print("0", end="")	
			for j in range(1, B):
				print("1", end="")
			print()
		elif M == 1:
			for j in range(0, B-1):
				print("0", end="")
			print("1", end="")
			print()

		else:
			binM = "0"*(B-1-len(binM)) + binM + '0'
			print("0", end="")
			for i in range(1,B):
				if binM[i] == '1':
					print("1", end="")
				else:
					print("0", end="")
			print()


					


		for i in range(1, B-1):
			for j in range(B):
				if( j > i ):
					print("1", end="")
				else:
					print("0", end="")
			print()
		for j in range(B):
			print("0", end="")
		print()

	else:
		print("IMPOSSIBLE")