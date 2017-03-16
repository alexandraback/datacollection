T = int(raw_input())
for t in xrange(T):
	ins = map(int, raw_input().split())
	K = ins[0]
	C = ins[1]
	S = ins[2]

	k = 0
	save = []
	while True:
		cur = 0;
		doop = 1
		while True:
			cur = cur + (k * (K ** (C-doop)))
			k += 1

			if doop == C or k >= K: 
				break;
			doop += 1

		save.append(cur)
		if k >= K: break

	save = [a+1 for a in save]

	if len(save) > S:
		print "Case #" + str(t+1) + ": " + "IMPOSSIBLE"
	else:
		print "Case #" + str(t+1) + ": " + " ".join(map(str, save))