
# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.



  # check out .format's specification for more formatting options



# f = open('A-small-practice.in.txt', 'r')

# for line in f.readlines():
    
#     if str(line) == "100":
#         pass
#     print(line)

#     # print(str(line), end='')
#     s_max, sequence = line.split(" ")
#     print(s_max, sequence)

t = int(input())  # read a line with a single integer
for i in range(1, t + 1):  
  n = int(input())  # read a list of integers, 2 in this case
  # print(n, end=" ")
  set_result=set()
  if n == 0:
    answer = "INSOMNIA"
    print("Case #{}: {}".format(i, answer))
    continue
  x = 1 
  while x:
    set_result = set_result | set([int(tmp) for tmp in str(n*x)])
    if set_result == set(range(10)):
      answer = n*x
      print("Case #{}: {}".format(i, answer))
      break
    x += 1 

  


