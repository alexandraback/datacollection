from bisect import bisect_left
from copy import copy
import sys
sys.setrecursionlimit(10000)

INC=0.0000001

def smallest_havier(n_b, k_bs):
	i = bisect_left(k_bs, n_b)
	if i == len(k_bs):
		return (k_bs[0],0)
	return (k_bs[i], i)

def closest(n_b, k_bs):
        i = bisect_left(k_bs, n_b)
        if i == len(k_bs):
                return (k_bs[-1],len(k_bs)-1)
        return (k_bs[i], i)

def war(n_bs, k_bs):
	score = 0
	l_k_bs = copy(k_bs)
	for n_b in n_bs:
		b = closest(n_b, l_k_bs)
		if n_b > b[0]:
			score += 1
		l_k_bs.pop(b[1])
	return score

def d_war(n_bs, k_bs):
	score = 0 
	l_k_bs = copy(k_bs)
	l_n_bs = copy(n_bs)
        r_n_bs = copy(n_bs)
	r_n_bs.reverse()
	for n_b in r_n_bs:
		if n_b > l_k_bs[-1]:
			score+=1
			l_n_bs.pop(-1)
			l_k_bs.pop(-1)
		else:
			b_t = l_k_bs[-1] - INC
			n = l_n_bs.pop(0)
			k = l_k_bs.pop(-1)
			score += d_war(l_n_bs, l_k_bs)
			break
			
	return score
		
#f = open("d_test.txt", "r")
#f2=open("d_test.out", "w")
f = open("D-large.in", "r")
f2=open("D-large.out", "w")


num_cases = int(f.readline().strip())

for i in range(num_cases):
        f2.write("Case #" + str(i+1)+": ")
        print "Case #" + str(i+1)+":"

	num = int(f.readline().strip())
	n_bs = [float(x) for x in f.readline().strip().split(' ')]
	k_bs = [float(x) for x in f.readline().strip().split(' ')]

	n_bs.sort()
	k_bs.sort()

	w_score = war(n_bs, k_bs)
	print w_score	
	dw_score = d_war(n_bs, k_bs)
	print dw_score
	
	f2.write(str(dw_score))
	f2.write(" ")
	f2.write(str(w_score))
	f2.write("\n")
f.close()
f2.close()

