
import sys, string, math, bisect
rl = lambda: sys.stdin.readline().strip()

intab  = "abcdefghijklmnopqrstuvwxyz"
outtab = "01110111011111011111011111"
trantab = string.maketrans(intab, outtab)

for cs in xrange(1,int(rl())+1):
	word, n=rl().split()
	n = int(n)
	#print word, n, word.translate(trantab)
	word = word.translate(trantab)

	# find start indexes
	start_indexes = list()
	inconseq=False
	num_conseq = 0

	for i in xrange(len(word)):
		if word[i]=='1':
			inconseq = True
			num_conseq += 1
			if num_conseq >= n:
				start_indexes.append(i-n+1)
		else:
			inconseq = False
			num_conseq = 0
#		print i, inconseq, num_conseq

	#print start_indexes

	last_start = 0
	num_subs = 0
	for j in start_indexes:
		possible_starts = j - last_start + 1
		possible_ends = len(word)-j-n+1
		num_subs += possible_ends * possible_starts
		#print possible_starts, possible_ends, possible_starts * possible_ends
		last_start = j+1

	#print num_subs
	print "Case #{0}: {1}".format(cs,num_subs)






