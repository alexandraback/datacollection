#T = int(raw_input())

T = 1
N = 16
J = 50

def to_bin(x):
	if x == 0:
		return "0"
	if x == 1:
		return "1"
	return to_bin(x/2) + str(x%2)

def make_pad(i, num):
	out = to_bin(i)
	return "0"*(num - len(out)) + out


def doprob():
#	read = raw_input()
#	N, J = read.split()
#	N = int(N)
#	J = int(J)
	myr = N/2 - 2
	out = '\n'
	if 2**myr < J:
		raise ValueError
	for i in xrange(J):
		out += "1" + make_pad(i, myr) + "11" + make_pad(i, myr) + "1"
		for j in xrange(2, 11):
			out += " " + str(j**(N/2)+1)
		out += '\n'
	return out

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())