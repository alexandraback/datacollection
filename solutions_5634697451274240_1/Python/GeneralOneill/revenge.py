def flip(l, end):
    for index in range(0, end + 1):
        if l[index] == "+":
            l[index] = "-"
        elif l[index] == "-":
            l[index] = "+"
    return l

def count(stack):
    count = 0
    for i, sign in enumerate(stack):
        index = "".join(stack).rfind("-")
        if(index != -1):
            stack = flip(stack, index)
            count += 1
    return count

cases = int(raw_input())
for case in range(cases):
    stack = list(raw_input())
    val = count(stack)
    print("Case #" + str(case+1) + ": " + str(val))
