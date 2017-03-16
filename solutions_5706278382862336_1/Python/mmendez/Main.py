def gcd(a,b):
	if a == 0:
		return b
	if b == 0:
		return a
	if b > a:
		return gcd(a, b % a)
	else:
		return gcd(b, a % b)

def solve():
    T = int(reader.r())+1
    for t in xrange(1,T):
        case = "Case #%d: %s"
        a,b = (int(x) for x in reader.r().split('/'))
        c = 0
        x = gcd(a,b)
        if x <> 1:
        	a /= x
        	b /= x
        if (b & (b - 1)) <> 0:
            print case % (t, "impossible")
        else:
            while a < b:
                a *= 2
                c += 1
            print case % (t, str(c))

class reader:
    buffer = []
    @staticmethod
    def r():
        if not reader.buffer:
            reader.buffer = raw_input().split()
        temp = reader.buffer[0]
        reader.buffer = reader.buffer[1:]
        return temp
    @staticmethod
    def rl():
        return raw_input()

solve();