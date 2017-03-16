def b_base_to_decimal(number, base):
	decimal = 0
	n = 0
	while number:
		decimal += (number % 10) * (base**n)
		number //= 10
		n += 1
	return decimal

def coin_increment(number):
	n = 1
	number //= 10
	while number:
		if number % 10 == 0:
			return (number + 1) * 10**n + 1
		number //= 10
		n += 1


def find_factor(number):
	for i in range(2, number):
		if number % i == 0:
			return i

		#Heuristic to say is prime
		if i > 100:
			break
	return None


if __name__ == "__main__":
	number_cases = int(input())
	for i in range(number_cases):
		inp = input()
		N, J = int(inp[:inp.find(' ')]), int(inp[inp.find(' ')+1:])

		print("Case #%s:" % (i+1))

		current_coin = 10**(N-1) + 1
		jamcoins = []

		while len(jamcoins) < J:

			is_jamcoin = True
			divisors = []
			for b in range(2, 11):
				divisor = find_factor(b_base_to_decimal(current_coin, b))

				if divisor is None:
					is_jamcoin = False
					break

				divisors.append(divisor)

			if is_jamcoin:
				info = [current_coin]
				info.extend(divisors)
				jamcoins.append(info)

			current_coin = coin_increment(current_coin)

		for jamcoin in jamcoins:
			print(' '.join([str(num) for num in jamcoin]))







