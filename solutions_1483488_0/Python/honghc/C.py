input = open('./sample.txt', 'r')
output = open('./output.txt', 'w')
case = int(input.readline())
def re(p,i):
	out = str(p)
	out = out[i%len(out):] + out[0:i%len(out)]
	return int(out)

def get_re(n):
	o = []
	for i in range(len(str(n)))[1:]:
		r = re(n,i)
		if r not in o:
			o.append(re(n,i))
	return o

def how_many_re(n,B):
	re = get_re(n)
	out = 0
	for i in re:
		if i <= B and i > n:
			#print 'n={0}, m={1}'.format(n,i)
			out = out + 1
	return out

def main(A,B):
	out = 0
	for n in range(B+1)[A:]:
		out = out + how_many_re(n,B)
	return out

for i in range(case):
	a = input.readline().split(' ')
	o = main(int(a[0]),int(a[1]))
	output.write('Case #{0}: {1}\n'.format(i+1, o))
	print 'Case #{0}: {1}'.format(i+1, o)