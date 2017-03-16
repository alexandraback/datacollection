def CountingSheep(n):
    if n:
        last_number = 0
        counted_digit = [0]*10
        while(counted_digit != [1]*10):
            last_number += n
            strn = '%d' % last_number
            for item in strn:
                counted_digit[int(item)] = 1
        return last_number
    else:
        return 'INSOMNIA'



# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
	n = int(input())  # read a list of integers
	s = CountingSheep(n)
	print("Case #{}: {} ".format(i, s))
  # check out .format's specification for more formatting options