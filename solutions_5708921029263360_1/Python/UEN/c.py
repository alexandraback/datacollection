import sys
import math
import copy

CASE =list();

with open("C-large.in") as f :
#with open("C-small-attempt1.in") as f :
#with open("input.txt") as f :
	T = int(f.readline());
	for line in f :
		CASE.append([int(x) for x in line.split()]);

print T, CASE;
#TP = list()
#NEW = copy.deepcopy(TOPIC);
#print (id(TOPIC))
#print (id(NEW))
#print (TOPIC)
#print T
#print N
#print TOPIC

with open("C-large.txt", 'w') as f :
#with open("C-samll1.txt", 'w') as f :
#with open("output.txt", 'w') as f :
	for T in range(0, T) :
		A = list();
		SUBJP = list();
		SUBJS = list();
		SUBPS = list();
		J = CASE[T][0]
		P = CASE[T][1]
		S = CASE[T][2]
		K = CASE[T][3]
		COUNT = 0;
		data = "Case #%d: " % (T+1);
		for j in range(1,J+1) :
			for p in range(1,P+1) :
				for s in range(1,S+1) :
					if (SUBJP.count([j,p]) < K) and (SUBJS.count([j,s]) < K) and (SUBPS.count([p,s]) < K) :
						if j!=p and p!=s and j!=s :
							A.append([j,p,s]);
							COUNT +=1;
							SUBJP.append([j,p]);
							SUBJS.append([j,s]);
							SUBPS.append([p,s]);
							
		for j in range(1,J+1) :
			for p in range(1,P+1) :
				for s in range(1,S+1) :
					if (SUBJP.count([j,p]) < K) and (SUBJS.count([j,s]) < K) and (SUBPS.count([p,s]) < K) :
						if j==p or p==s or j==s :
							A.append([j,p,s]);
							COUNT +=1;
							SUBJP.append([j,p]);
							SUBJS.append([j,s]);
							SUBPS.append([p,s]);
								
		print COUNT, A
		data += "%d\n" % COUNT;
		f.write(data);
		for a in A :
			data = ""
			data += str(a[0]) + " " + str(a[1]) + " " + str(a[2]) + "\n"
			f.write(data)


