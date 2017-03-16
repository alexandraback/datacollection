import string
def count(s,k,c):
	res = 0
	for i in s:
		res = res * k
		res = res + i
		c = c - 1
	res = res * (k ** c)
	return res

def solve(k,c,s):
	if((s * c) < k):
		return "IMPOSSIBLE"
	else:
		a = []
		ss = []
		queue = []
		for i in range(k):
			if (i%c == 0):
				a.append(ss)
				ss = []
			ss.append(i)
		a.append(ss)
		for ss in a:
			if (len(ss)>0):
				queue.append(count(ss,k,c) + 1)
                queue_str = []
                for value in queue:
                        queue_str.append("%d" %value)
                res_str = " ".join(queue_str)
		return res_str

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    k, c, s = [int(ss) for ss in raw_input().split(" ")]  # read a list of integers, 2 in this case
    case_str = "Case #%d: " %i
    print case_str + solve(k,c,s)
