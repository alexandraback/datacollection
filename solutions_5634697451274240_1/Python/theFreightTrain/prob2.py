def reverse(stack):
    newStack = ''
    for i in range(1,len(stack)+1):
        newStack += '+' if stack[-i]=='-' else '-'
    return newStack
    
def badFlip(stack):
    newStack = ''
    i = 0
    while(stack[i]=='+'):
        newStack+='-'
        i+= 1
    return newStack + stack[i:]

def howManyFlips(stack):
    if (len(stack)==0):
        return 0
    elif (stack[-1]=='-' and stack[0]=='-'):
        return 1 + howManyFlips(reverse(stack)[:-1])
    elif (stack[-1]=='-' and stack[0]=='+'):
        return 1 + howManyFlips(badFlip(stack))
    else:
        return howManyFlips(stack[:-1])
    
t = int(input())
for i in range(1, t + 1):
  stack = input()
  print("Case #{}: {}".format(i, howManyFlips(stack)))
  

