def recurClass(next,dig_dict,path_list):
	for nextClass in next:
		path_list.append(int(nextClass))
		recurClass(dig_dict[int(nextClass)],dig_dict,path_list)

with open('A-small-attempt0.out', 'w') as fout:
	with open('A-small-attempt0.in', 'r') as fin:
		tc=int(fin.readline())
		diamond=False
		for tc_no in range(tc):
			N=int(fin.readline().strip())
			dig_dict={}
			for myClass in range(N):
				dig_dict[myClass+1]=[]
				inh_list=[]
				for path in fin.readline().split(' ')[1:]:
					inh_list.append(path.strip())
				dig_dict[myClass+1]=inh_list
			for myClass in dig_dict.keys():
					path_list=[]
					path_list.append(myClass)
					recurClass(dig_dict[myClass],dig_dict,path_list)
					if (len(path_list)!= len(list(set(path_list)))):
						diamond=True
						fout.write("Case #" + str(tc_no+1) + ": Yes" + '\n')
						break
			if not diamond:
				fout.write("Case #" + str(tc_no+1) + ": No" + '\n')
			diamond=False
