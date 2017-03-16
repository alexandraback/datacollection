import sys
dict={'11':'1','1i':'i','1j':'j','1k':'k',
'i1':'i','ii':'1','ij':'k','ik':'j',
'j1':'j','ji':'k','jj':'1','jk':'i',
'k1':'k','ki':'j','kj':'i','kk':'1'}
dict_sign={'11':1,'1i':1,'1j':1,'1k':1,
'i1':1,'ii':-1,'ij':1,'ik':-1,
'j1':1,'ji':-1,'jj':-1,'jk':1,
'k1':1,'ki':1,'kj':-1,'kk':-1}
[N, L, X, N_cnt] = [0, 0, 0, 0]
for line in sys.stdin:
	if N == 0:
		N = int(line.split("\n")[0])
	else:
		N_cnt += 1
		if N_cnt % 2 == 1:
			L = int(line.split("\n")[0].split(' ')[0])
			X = int(line.split("\n")[0].split(' ')[1])
		else:
			s=[]
			sign=1
			check=0
			[i, j ,k]=[[], [], []]
			if L * X < 3:
				print "Case #{0}: {1}".format(str(N_cnt/2), 'NO')
			else:
				s = ' '.join(line.split("\n")[0]).split(' ')
				if 'i' in s:
					check += 1
				if 'j' in s:
					check += 1
				if 'k' in s:
					check += 1
				if check > 1:
					tmp_S = s
					#for z in range(0,X-1):
					#	s += tmp_S	
					while X >= 1:
						X -=1
						s = ['1'] + s
						if i==[]:
							for z in range(0,len(s)-1):
								tmp=''.join(s[0:2])
								s = [dict[tmp]]+s[2:]
								sign *= dict_sign[tmp]
								if s[0] == 'i' and sign==1:
									if i == []:
										i = s[0]
										s = s[1:]
										break
						s = ['1'] + s
						if i!=[] and j==[]:
							for z in range(0,len(s)-1):
								tmp=''.join(s[0:2])
								s = [dict[tmp]]+s[2:]
								sign *= dict_sign[tmp]
								if s[0] == 'j' and sign==1:
									if j == [] and i != []:
										j = s[0]
										s = s[1:]
										break
						s = ['1'] + s
						if i!=[] and j!=[]:
							for z in range(0,len(s)-1):
								tmp=''.join(s[0:2])
								s = [dict[tmp]]+s[2:]
								sign *= dict_sign[tmp]
						s = s + tmp_S
					if i != [] and j!=[] and s[0] == 'k' and sign==1:
						print "Case #{0}: {1}".format(str(N_cnt/2), 'YES')
					else:
						print "Case #{0}: {1}".format(str(N_cnt/2), 'NO')
				else:
					print "Case #{0}: {1}".format(str(N_cnt/2), 'NO')
				
				
			