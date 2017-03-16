import sys
import itertools

def get_subsets(line):
  num_arr=[]
  list_dict={}
  line_split = line.split(" ")
  for i in range(1,int(line_split[0])+1):
    num_arr.append(int(line_split[i]))
  flag=0
  out_str="\n"
  for i in range(1,len(num_arr)+1):
    if flag==0:
      l= list(itertools.combinations(num_arr,i))
      for t in l:
        if sum(t) in list_dict:
          for elem in t:
            if elem:
              out_str+= str(elem)+" "
          out_str+="\n"
          temp = list_dict[sum(t)]
          for elem in temp:
            if elem:
              out_str+=str(elem)+" "
          flag=1
          break 
        else:
          list_dict[sum(t)]=t
 
  if flag==0:
    return "Impossible"
  else:
    return out_str

f=open(sys.argv[1],'r').read()
f_lines = f.split('\n')
num_times = int(f_lines[0])
for i in range(0, num_times):
  line = f_lines[i+1]
  print "Case #"+str(i+1)+": "+get_subsets(line) 
