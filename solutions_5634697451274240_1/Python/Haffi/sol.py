import fileinput

data = fileinput.input()
T = int(data[0])

for i in range(1,T+1):
    stack = data[i][:-1]
    idx = 0
    num_swaps = 0
    while idx < len(stack)-1:
        while idx < len(stack)-1 and (stack[idx] == stack[idx+1]):
            idx += 1
        if num_swaps == 0 and idx == len(stack) - 1 and stack[0] == '+':
            num_swaps = 0
        elif idx < len(stack)-1:
            num_swaps += 1
            idx += 1
    if stack[-1] == '-':
        num_swaps += 1
    print("Case #{}: {}".format(i,num_swaps))


