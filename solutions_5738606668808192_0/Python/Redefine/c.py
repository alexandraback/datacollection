from math import sqrt

def generate_jamcoins(num, length):
	jamcoin = '1' + '0' * (length - 2) + '1'
	max_bin = int('1' * length, 2)
	jamcoins = []
	while len(jamcoins) < num:
		check, factors = check_jamcoin(jamcoin)
		if check:
			jamcoins.append(jamcoin + ' ' + ' '.join(map(str, factors)))
		jamcoin = bin(int(jamcoin, 2) + 2)[2:]
		if int(jamcoin, 2) > max_bin:
			return -1
	return jamcoins

def check_jamcoin(jamcoin):
	multiples = []
	for base in range(2, 11):
		base10 = base2_to_n(jamcoin, base)
		factor = find_first_factor(base10)
		if factor == -1:
			return False, multiples
		else:
			multiples.append(factor)
	return True, multiples

def base2_to_n(binary, n):
	binary = binary[::-1]
	total = 0
	for i in range(len(binary)):
		if binary[i] == '1':
			total += n ** i
	return total

def find_first_factor(n):
	for i in range(2, int(sqrt(n)) + 1):
		if n % (n // i) == 0:
			return i
	else:
		return -1

def main():
	with open('C-small.in', 'r') as a:
	    text = a.readlines()
	    a.close()
	b = open('C-small.out', 'w+')
	cases = int(text[0])
	for i in range(1, cases + 1):
		b.write("Case #{}:\n".format(i))
		N = int(text[i].split()[0])
		J = int(text[i].split()[1])
		jamcoins = generate_jamcoins(J, N)
		if jamcoins == -1:
			b.write('FAILED')
		else:
			for jamcoin in jamcoins:
				b.write(jamcoin + '\n')
	b.close()

if __name__ == "__main__":
    main()