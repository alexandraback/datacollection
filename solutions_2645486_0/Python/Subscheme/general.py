def solve(start_t,end_t,start_e,end_e):
	if start_t == end_t: return 0
	global E,N,R,val
	task = max(range(start_t,end_t),key=lambda t: (val[t],-t))
	to_use = min(E,start_e+R*(task-start_t)) - max(end_e-R*(end_t-task),0)
	return to_use * val[task] + solve(start_t,task,start_e,start_e) + solve(task+1,end_t,min(E,start_e+R*(task-start_t))-to_use+R,end_e)

fin = open('input.txt')
fout = open('output.txt','w')

get = lambda: map(int,fin.readline().split())

cases, = get()
for case in range(1,cases+1):
	E,R,N = get()
	val = get()
	fout.write('Case #%d: %d\n' % (case,solve(0,N,E,0)))
	print
	print