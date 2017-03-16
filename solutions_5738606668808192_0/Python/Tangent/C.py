import sys
def main():
	name, pathin, pathout = sys.argv

	filein = open(pathin)
	fileout = open(pathout,'w')
	fileout.write('Case #1:\n')

	total = int(filein.readline())
	results = []
	for case in range(total):
		N, J = [int(_) for _ in filein.readline().split()]
		g = generate(N-2)
		for i in range(J):
			results = next(g)
			fileout.write(' '.join(results)+'\n')


def primelist(n):
	li = []
	trash = set()

	for base in range(2, n+1):
		if base in trash:
			pass
		else:
			li.append(base)
			i = 1
			while base*i <= n:
				trash.add(base*i)
				i += 1
	return li

def generate(width):

	plist = primelist(10000)

	def check(n):
		for prime in plist:
			if n%prime == 0:
				return prime
		return False

	number = '1'+'0'*width+'1'

	while True:
		result = [number]
		flag = True
		for base in range(2, 11):
			transfer = int(number, base)
			divisor = check(transfer)

			if divisor:
				result.append(str(divisor))
			else:
				flag = False
				break
		if flag:
			yield result
		number = bin(int(number,2)+2)[2:]


if __name__ == '__main__':
	main()


