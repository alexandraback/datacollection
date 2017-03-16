
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
      n, j = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
      result=[]
      for x in range(2**(n-1) + 1, 2**n,2):
            x = bin(x)[2:]
            count = 0
            for div in range(3,12):                    
                if int(str(x),div-1)%div == 0:                        
                    count += 1                    
            if count == 9:
                result.append([ x ,"3","4","5","6","7","8","9","10","11"])
                if len(result) >= j:
                    break
print("Case #{}:".format(1))
for num in result:
    print(" ".join(num))

