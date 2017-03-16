
def f(E, R, v_lst):
	R = min(max(R,E), R)
	l = len(v_lst)
	r_lst = [E]*l
	w_lst = [0] *l
	sorted_lst =[i[0] for i in  sorted(enumerate(v_lst), key = lambda t:t[1], reverse = True) ]
	for i in sorted_lst:
		w = min (r_lst[i], E); w_lst[i] = w
		k = min(w/R, i)
		for j in range(k, 0, -1):
			r_lst[i-j] =  min (r_lst[i-j], (k-j+1) * R + E-w)
		k = min(w/R, l-i-1)
		for j in range(0, k):
			r_lst[i+j+1] = min ((j+1) * R, r_lst[i+j+1])
	return sum ([w*v for w,v in zip(w_lst,v_lst)])
for i in range(int(raw_input())):
	E,R,n = map(int, raw_input().split())
	v_lst = map(int, raw_input().split())
	print "Case #%d: %d" %(i+1, f(E,R,v_lst))
