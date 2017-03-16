import sys
import math
import StringIO
import os
import re

target_dir = 'C:\\Users\\lijia_000\\Downloads'
def search_file():
	problem_id = os.path.basename(sys.argv[0]).split('.')[0].lower()
	large_list = filter(lambda x: re.match('^%s.*large.*\.in$' % problem_id, x.lower()) is not None, os.listdir(target_dir))
	if large_list:
		return max(large_list)
	small_list = filter(lambda x: re.match('^%s.*small.*\.in$' % problem_id, x.lower()) is not None, os.listdir(target_dir))
	if small_list:
		return max(small_list)
	sys.stderr.write("No file available\n")

def problem_solver(fileobj_in, fileobj_out):
	n = int(fileobj_in.readline())
	for i in xrange(n):
		result = case_solver(**case_reader(fileobj_in))
		assert(type(result) is str)
		if not result.endswith('\n'): result += '\n'
		fileobj_out.write("Case #%d: %s" % (i+1, result))
def main():
	problem_solver(f_in, f_out)

file_name = None
file_name = search_file()
if file_name:
	print "using file:",file_name
	f_in = open(os.path.join(target_dir, file_name), 'r')
	f_out = open(os.path.basename(file_name[:-3]) + '.out', 'w')
else:
	f_out = sys.stdout
	f_in = StringIO.StringIO("""
7
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
5 1
kjikk
5 1
iikji
""".lstrip())

idx={'1':0,'i':1,'j':2,'k':3}
qua=[
	['1','i','j','k'],
	['i','-1','k','-j'],
	['j','-k','-1','i'],
	['k','j','-i','-1']
]
def qc(l,r):
	ll,rr = l,r
	s = 1
	if l[0] == '-':
		ll = l[1:]
		s *= -1
	if r[0] == '-':
		rr = r[1:]
		s *= -1
	res = qua[idx[ll]][idx[rr]]
	if s < 0:
		if res[0] == '-': res = res[1:]
		else: res = '-' + res
	return res

def case_reader(fileobj):
	l,x = map(int,fileobj.readline().strip().split())
	p = fileobj.readline().strip()
	return {"l": l, "p": p, "x": x}

def case_solver(**arg):
	ret = calsmart(arg['p'],arg['x'])
	return str(ret)

def search_head(p,t):
	s = '1'
	for i in xrange(len(p)):
		s = qc(s, p[i])
		if s == t:
			return i

def search_tail(p,t):
	s = '1'
	for i in xrange(len(p)-1, -1, -1):
		s = qc(p[i], s)
		if s == t:
			return i

def calstupid(p,x):
	pp = p * x
	s1 = reduce(qc, pp)
	if s1 != '-1': return "NO"
	l = search_head(pp, 'i')
	r = search_tail(pp, 'k')
	if l is not None and r is not None and l < r:
		print l,r
		return "YES"
	return "NO"

def calsmart(p,x):
	s1 = reduce(qc, p)
	if x % 4 == 0: return "NO"
	if reduce(qc, [s1] * (x % 4)) != '-1': return "NO"
	t = p * 4
	l = search_head(t, 'i')
	r = search_tail(t, 'k')
	if l is None or r is None: return "NO"
	r = len(t) - r
	if len(p) * x - l - r > 0:
		return "YES"
	return "NO"

if __name__ == '__main__':
	main()
	print qc(qc('i','j'),'k')

	pass