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
4
1
3
4
1 2 1 2
1
4
4
7 7 7 7
""".lstrip())

def case_reader(fileobj):
	n = int(fileobj.readline())
	p =map(int,fileobj.readline().strip().split())
	return {"n": n, "p": p}

def case_solver(**arg):
	p = arg['p']
	n = arg['n']
	ret = min((calcmin(t,p) for t in range(1,max(p)+1)))
	return str(ret)

def calcmin(t,p):
	return sum(((d-1) / t for d in p)) + t

if __name__ == '__main__':
	main()
	pass