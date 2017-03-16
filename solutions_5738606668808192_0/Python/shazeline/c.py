import random

def rmpt(num):
    s = num - 1
    t = 0
    while s % 2 == 0:
    	s = s // 2
        t += 1

    for trials in range(5):
        a = random.randrange(2, num - 1)
        v = pow(a, s, num)
        if v != 1:
            i = 0
            while v != (num - 1):
                if i == t - 1:
                    return False
                else:
                    i = i + 1
                    v = (v ** 2) % num
    return True

def is_prime(n):
	if n < 2:
		return False
	if n == 3:
		return True
	if n % 2 == 0:
		return False
	return rmpt(n)

def convert(j, b):
	tot = 0
	strj = str(j)[::-1]
	for i, x in enumerate(strj):
		if x == '1':
			tot += b ** i
	return tot

def ally(j):
	return [convert(j, i) for i in xrange(2, 11)]

def gen_poss(N):
	maxnum = 2 ** (N-1)
	minnum = 2 ** (N-2)
	return ["{0:b}1".format(i) for i in xrange(minnum, maxnum)]

def bins(N):
	ans = []
	for num in gen_poss(N):
		poss = ally(num)
		good = True
		for p in poss:
			if is_prime(p):
				good = False
				break
		if good:
			ans.append(num)
		if len(ans) == 50:
			break
	return ans

def get_fac(n):
	for i in xrange(2, int(n ** .5) + 1):
		if n % i == 0:
			return i


from collections import defaultdict


sols = bins(16)
# print sols

# print gen_poss(4)

mp = defaultdict(list)
print 'CASE #1:'
for s in sols:
	a = '%s' % s
	# print ally(s)
	fs = [str(get_fac(x)) for x in ally(s)]
	print '%s %s' % (a, ' '.join(fs))

# for k in mp:
	# print '%s %s' % (k, ' '.join(map(str, mp[k])))

# print mp
# print sols
# print bins(4)
# print rmpt(5)
# print bins(16)






# print rmpt(1111111111111111)
