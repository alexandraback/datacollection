import string

fn = "C-small-attempt0.in"

f= open(fn,'r')

summap = {}
datas = []
def decode(b1, b2):
	list1 = []
	list2 = []
	place = -1
	for x in xrange( len(datas)):
		place+=1
		if b1 &1 == 1:
			list1.append(datas[place])
		b1 = b1>>1
		if b2 &1 == 1:
			list2.append(datas[place])
		b2 = b2>>1
	
	if len(list1)>= 1 and len(list2) >=1 :
		return (list1, list2)
	#print "OMG"
	

def testadd(newset):
	#print newset, summap
	for each in newset:
		sum, bitmap = each
		if summap.has_key(sum):
			subs = summap[sum]
			for items in subs:
				if items & bitmap == 0:
					#print "got you"
					return decode(items, bitmap)
					
	
	for each in newset:
		sum, bitmap = each
		if summap.has_key(sum):
			summap[sum].append(bitmap)
		else:
			summap[sum] = [bitmap]
			
					#else:
				#summap[sum].append(bitmap)
			#return None
		#else:
			#summap[sum] = [bitmap]
	
	return None

tcase = int(f.readline())

for tc in xrange(tcase):
	line = f.readline()
	#print line
	linedata = line.split()
	n = int(linedata[0])
	#print n
	summap = {}
	datas = []
	res = None
	for d in xrange(n):
	#for d in xrange(3):
		
		data = int(linedata[d+1])
		sbm = 1<<d
		ns = data
		datas.append(data)
		newset= [(ns, sbm)]
		#res = testadd(ns, sbm)
		#if res != None:
#			break
		#print summap
		for k, subs in summap.items():
			for bm in subs:
				# make union
				nbm = (1<<d) | bm
				ns = data + k
				newset.append( (ns,nbm))
				#res = testadd(ns, nbm)
#				if res != None:
#					break
			else:
				continue
			#if res!= None:
			#	break
		#testadd(newset)
		res = testadd(newset)
		#print summap
		#print
		if res != None:
			
			break
		
	if res != None:
		print "Case #%d:"%(tc+1)
		s1= res[0]
		s2 = res[1]
		line1 = ""
		for i1 in s1:
			line1 = line1+ " " + str(i1)
		print line1[1:]
		line2 = ""
		for i2 in s2:
			line2 = line2+ " " + str(i2)
		print line2[1:]
		
	else:
		print "Case #%d:"% (tc+1)
		print "Impossible"
