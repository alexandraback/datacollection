def Pancake(stack):
    n = len(stack)
    for i in range(1,len(stack)):
        if stack[i] == stack[i-1]:
            n -= 1
    if stack[len(stack)-1] == '+':
        n -= 1
    return n

t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
	stack = input()  # read a list of integers
	n = Pancake(stack)
	print("Case #{}: {} ".format(i, n))
