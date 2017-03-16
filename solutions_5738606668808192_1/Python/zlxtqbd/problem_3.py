def gen_bi_seqs(result, seq, length, count):
	if len(seq) == length:
		result.append(seq)
	else:
		if len(result) > count:
			return
		else:
			gen_bi_seqs(result, seq+"0", length, count)
		if len(result) > count:
			return
		else:
			gen_bi_seqs(result, seq+"1", length, count)


for t in range(int(raw_input())):
	data = raw_input().split();
	N = int(data[0])
	J = int(data[1])

	print "Case #%d:" % (t+1)

	bi_seqs = [] # binary sequences
	gen_bi_seqs(bi_seqs, "", (N - 2) / 2, J)
	bi_seqs.remove("0" * ((N - 2) / 2)) # "00...0" can't be in there
	#print bi_seqs
	#print len(bi_seqs)

	for seq in bi_seqs:
		new_seq = "1" + seq
		while new_seq[len(new_seq)-1] == "0":
			new_seq = new_seq[:-1]
		l = len(new_seq)
		print new_seq + "0" * (N - 2 * l) + new_seq,
		for b in range(2, 11):
			factor = 0
			for i in range(l):
				factor += int(new_seq[i]) * (b**(l-1-i))
			print factor, 
		print 


