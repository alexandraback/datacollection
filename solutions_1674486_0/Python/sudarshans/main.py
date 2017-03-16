from __future__ import division

def doit(index):
	#we start at index and move up
	if inh_from[index]!=[]:
		return
	for parent in class_inh[index]:
		doit(parent-1)
	#parents all done, update child data
	inh_from[index].append(index)
	for parent in class_inh[index]:
		inh_from[index].extend(inh_from[parent-1])

def case():
	numclasses=int(raw_input())
	global class_inh
	global inh_from
	class_inh=[]
	inh_from=[]
	for i in xrange(0,numclasses):
		#ith class inh
		vals=map(int,raw_input().split()[1:])
		class_inh.append(vals)
		inh_from.append([])
	#start at class_inh[0] and move up the hierarchy
	for k,v in enumerate(class_inh):
		doit(k)
	for iter in inh_from:
		iter.sort()
		_len=len(iter)-1
		for i in xrange(0,_len):
			if iter[i]==iter[i+1]:
				print "Yes",
				return
	print "No",
	return

numcases=int(raw_input())
for i in xrange(0,numcases):
	print "Case #%d:"%(i+1),
	#case specific code here
	case()
	print
