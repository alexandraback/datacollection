import sys
import math
import StringIO
import os
import re

target_dir = 'C:\\Users\\lijia_000\\Downloads'
def search_file():
	problem_id = os.path.basename('a.py').split('.')[0].lower()
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
	f_in = open(os.path.join(target_dir, file_name), 'r')
	f_out = open(os.path.basename(file_name[:-3]) + '.out', 'w')
else:
	f_out = sys.stdout
	f_in = StringIO.StringIO("""
5
4 11111
1 09
5 110011
0 1
3 0009
""".lstrip())

def case_reader(fileobj):
	n,s = fileobj.readline().strip().split()
	return {"n": int(n), "s": map(int, s)}

def case_solver(**arg):
	s = arg['s']
	n = arg['n']
	for i in range(n):
		s[i+1] += s[i]
	#print zip(range(1,n+2),s)
	return str(max(max((x-y for x,y in zip(range(1,n+2),s))), 0))

if __name__ == '__main__':
	main()
	pass