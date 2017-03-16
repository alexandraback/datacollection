
def isPrime(x):
    if x < 2: return 1
    if x == 2: return -1
    i = 2
    while i * i <= x:
        if x % i == 0:
            return i
        i += 1
    return -1

def base10ToBase2(val):
    return bin(val)[2:]

def base10ToBasex(val, x):
    ch = base10ToBase2(val)
    i = 0
    res = 0
    length = len(ch)
    while i < length :
        res += long((ord(ch[i]) - ord('0')) * (x ** (length - i - 1)))
        i += 1
    return res

if __name__ == '__main__':
	t = input()
	Case = 1
	while Case <= t:
		n = input()
		l = input()
		print "Case #"+str(Case)+":"
		Case += 1
		end = 1 << n
		start = 2147483687
		cnt = 0
		i = start
		while i < end:
			b = 2
			dx = 0
			res = []
			while b <= 10:
				val = base10ToBasex(i, b)
				yinzi = isPrime(val)

				if yinzi != -1: 
					res.append(yinzi)
					dx += 1
				else:
					dx = 0
					break
				b += 1
			if dx == 9:
				ans = ''
				ans += base10ToBase2(i) +' '
				j = 0
				while j < dx:
					ans += str(res[j])
					if j != dx - 1:
						ans += ' '
					j += 1
				print ans
				cnt += 1
				if cnt == l:
					break
			i += 2

