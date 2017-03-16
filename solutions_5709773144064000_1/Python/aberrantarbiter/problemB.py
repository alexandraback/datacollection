

def solve(vars):
	C = float(vars[0])
	F = float(vars[1])
	X = float(vars[2])
	current_rate = 2.0
	time_taken = 0.0
	cont = True
	while cont:
		win_time_now = X / current_rate
		win_time_aug = X / (current_rate + F)
		aug_time = C / current_rate
		print "%f vs. %f" % (win_time_now, win_time_aug)
		if win_time_now < win_time_aug + aug_time:
			print "Stopping at rate %f" % current_rate
			cont = False
			time_taken += win_time_now
		else:
			print "Buying farm at rate %f" % current_rate
			current_rate += F
			time_taken += aug_time
	return time_taken





def main():
	with open('input.txt','r') as f:
		problems = int(f.readline())
		answers = []
		for i in xrange(problems):
			vars = f.readline().split(' ')
			answers.append("Case #%d: %f" % (i+1, solve(vars)))
		with open('output.txt','w') as fout:
			fout.write('\n'.join(answers))




if __name__ == "__main__":
	main()