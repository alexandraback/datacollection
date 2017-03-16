import math
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.

def int_base(list, base):
    i = 0
    result = 0
    nums = [ int(i) for i in list ]
    nums.reverse()
    while i < len(nums):
        result +=  nums[i]*base**i
        i += 1
    return result

t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
  K, C, S = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
  # print(K, C ,S)
  # print(math.ceil(K / float(C)))
  # print(math.ceil(K / float(C)) < S)
  result=[]
  if  math.ceil(K / float(C)) > S:
    result.append("IMPOSSIBLE")
  elif C==1:
    result = [x+1 for x in range(K)]
  elif K ==1:
    result = [1]
  else:
    line = [x for x in range(K)]
    # print(line)
    tmp = [line[y:y+C] for y in range(0, len(line), C)]
    # print(tmp)
    for a in tmp:
        # print(a)
            result.append(int_base(a,K) +1)        
  # print(result)
  print("Case #{}: {}".format(i, " ".join( str(num) for num in result)))
  # check out .format's specification for more formatting options