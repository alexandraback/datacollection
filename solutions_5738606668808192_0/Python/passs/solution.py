from bitarray import bitarray

def find_coin_jams(N, J, file):
	print("Case #1:")
	file.truncate()
	file.write("Case #1:\n")
	n = N//2 - 2
	M = 2**n
	if M < J:
		print ("Oops")
		return -1
	divisors = [b**(N//2) + 1 for b in range(2,11)]
	for x in range(J):
		temp_string = "{0:b}".format(x).zfill(n)
		coin_jam = "1" + temp_string + "11" + temp_string + "1"
		res_string = coin_jam
		for i in range(9):
			res_string += " " + str(divisors[i])
		print(res_string)
		file.write(res_string + "\n")
	return 0

f_out = open("C://Users//Pavlo//Downloads//coin_jam_out.txt", "a")
find_coin_jams(16, 50, f_out)
