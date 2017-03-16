import sys

def get_percentage(line):
  line_split = line.split(' ')
  total_sum=0
  count=0
  revised_count=0
  judge_arr=[]
  final_arr=[]
  for i in range(1,int(line_split[0])+1):
    total_sum+= int(line_split[i])
    judge_arr.append(int(line_split[i]))
    count+=1
  total_sum=total_sum*2
  each_point = float(total_sum)/float(count)
  total_sum=total_sum/2
  t_sum=total_sum
  for p in judge_arr:
    if p>each_point:
      final_arr.append(0-1)
    else:
      final_arr.append(p)
      revised_count+=1
      t_sum+=p
 # print t_sum
 
  revised_each_point=float(t_sum)/float(revised_count)

  return_string=""
  
  for i in range(0,len(final_arr)):
    if final_arr[i]!=-1:
      x=final_arr[i]
      #print revised_each_point, x, total_sum
      res = ((revised_each_point-float(x))/float(total_sum))*100
      final_arr[i]=str(res)
    else:
      final_arr[i]=str(float(0))
  return_string=' '.join(final_arr)

  #for i in range(1, int(line_split[0])+1):
  #  return_string+= str((float(each_point)-float(int(line_split[i])))/(float(total_sum)/2)*100) + " "
  return return_string 

f= open(sys.argv[1]).read()
f_lines = f.split('\n')
num_times = int(f_lines[0])
for i in range(0, num_times):
  line = f_lines[i+1]
  print "Case #"+str(i+1)+": "+get_percentage(line) 
