import gcj
#from string import maketrans

trans = str.maketrans("+-", "-+")


def flip(stack, i):
	return stack[:i][::-1].translate(trans) + stack[i:]
	#print("Flip ", stack, i, r)
	#return r

def brute(stack, hist, mn):

	if mn != -1 and len(hist) >= mn:
		return mn

	if stack in hist:
		return -1

	if max(stack) == '+':
		#print("Found", len(hist), hist)
		return len(hist)


	b = mn
	for i in range(1, len(stack) + 1):
		bb = brute(flip(stack, i), hist + [stack], b)
		if bb != -1:
			if b == -1:
				b = bb
			else:
				b = min(b, bb)

	return b


def opt(stack, sym):
	#print(stack, sym)
	nsym = sym == '+' and '-' or '+'
	if stack[-1] == sym:
		i = len(stack) - 1
		while stack[i] == sym and i >= 0:
			i -= 1
		
		if i == -1:
			return 0

		return opt(stack[:(i + 1)], sym)
	else:
		i = len(stack) - 1
		while stack[i] == nsym and i >= 0:
			i -= 1
		
		if i == -1:
			return 1

		return 1 + opt(stack[:(i+1)], nsym)		


ifile, ofile = gcj.get_files('B')

T = int(ifile.readline().strip())
for t in range(T):
	ans = 0
	stack = ifile.readline().strip()
	#ans = brute(stack, [], -1)
	ans = opt(stack, '+')
	#ans = str(opt(stack, '+')) + ':' + str(brute(stack, [], -1))

	gcj.print_answer(ofile, t, ans)