chiffre = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
a = {'O', 'Z', 'T', 'H', 'F', 'W', 'V', 'R', 'U', 'E', 'X', 'G', 'N', 'I', 'S'}
p = [ (0,'Z'), (2, 'W'), (4, 'U'), (5, 'F'), (7, 'V'), (6, 'X'), (3, 'R'), (8, 'G'), (1, 'O'), (9, 'I')]

def main():
	T = int(input())
	for i in range(1,T+1):
		S = input()
		s = { k:S.count(k) for k in a }
		d = [0]*10
		for k,l in p:
			n = s[l]
			for c in chiffre[k]:
				s[c] -= n
			d[k] = n
		r = ''
		for k in range(10):
			r += str(k)*d[k]
		print('Case #%d: %s' % (i,r))



if __name__ == '__main__':
	main()